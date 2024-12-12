/* [주석 1: 과제 설명]
	
	컴퓨터 프로그래밍 및 실습 평가 과제 (배점 25점)
	학과 : 컴퓨터 공학과
	학번 : 202104473
	이름 : 고서영
	과제 주제 : 인테리어 구조 파악하기
	
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include "Assistant.h"
#include "Shape.h"
#include "BuildingInfo.h"
#include "UserPreferences.h"
#include "Constraints.h"
#include "InteriorOptimizer.h"
#include "StyleRecommender.h"

int main() {
    // 스타일 DB 읽기
    std::ifstream styleFile("style_db.txt");
    if(!styleFile.is_open()) {
        std::cerr << "Failed to open style_db.txt\n";
        return 1;
    }

    std::vector<std::pair<std::string,std::string>> styleDB; 
    // {styleName, colorPalette}
    {
        std::string stName, stColor;
        while(styleFile >> stName >> stColor) {
            styleDB.push_back({stName, stColor});
        }
    }
    styleFile.close();

    // 가구 DB 읽기
    std::ifstream furnFile("furniture_db.txt");
    if(!furnFile.is_open()) {
        std::cerr << "Failed to open furniture_db.txt\n";
        return 1;
    }

    std::vector<std::string> furnitureDB;
    {
        std::string fname;
        while(std::getline(furnFile, fname)) {
            if(!fname.empty()) {
                furnitureDB.push_back(fname);
            }
        }
    }
    furnFile.close();

    // 사용자에게 styleDB에서 선택하게 하기
    std::cout << "Available Styles:\n";
    for (size_t i = 0; i < styleDB.size(); i++) {
        std::cout << i+1 << ". " << styleDB[i].first << " (" << styleDB[i].second << ")\n";
    }

    std::cout << "Select a style number: ";
    size_t styleChoice;
    std::cin >> styleChoice;
    if (styleChoice < 1 || styleChoice > styleDB.size()) {
        std::cerr << "Invalid style choice, using default.\n";
        styleChoice = 1;
    }

    std::string chosenStyle = styleDB[styleChoice-1].first;
    std::string chosenColor = styleDB[styleChoice-1].second;

    // 집 형태 받기
    std::cout << "Select house shape (circle, rectangle, triangle): ";
    std::string shapeType;
    std::cin >> shapeType;

    Shape* shape = nullptr;
    if (shapeType == "circle") {
        double r;
        std::cout << "Enter radius: ";
        std::cin >> r;
        shape = new Circle(r);
    } else if (shapeType == "rectangle") {
        double w, h;
        std::cout << "Enter width and height: ";
        std::cin >> w >> h;
        shape = new Rectangle(w,h);
    } else if (shapeType == "triangle") {
        double b, ht;
        std::cout << "Enter base and height: ";
        std::cin >> b >> ht;
        shape = new Triangle(b, ht);
    } else {
        std::cerr << "Unknown shape. Defaulting to rectangle(10x8).\n";
        shape = new Rectangle(10.0, 8.0);
    }

    BuildingInfo* bInfo = new BuildingInfo(shape);

    double dx, dy;
    std::cout << "Enter door position (x y): ";
    std::cin >> dx >> dy;
    bInfo->addDoor(dx, dy);

    double wx, wy;
    std::cout << "Enter window position (x y): ";
    std::cin >> wx >> wy;
    bInfo->addWindow(wx, wy);

    double budgetMin, budgetMax;
    std::cout << "Enter budget range (min max): ";
    std::cin >> budgetMin >> budgetMax;
    UserPreferences prefs(chosenStyle, chosenColor, budgetMin, budgetMax);

    // 가구 DB 출력 후 선택
    std::cout << "Available Furnitures:\n";
    for (size_t i = 0; i < furnitureDB.size(); i++) {
        std::cout << i+1 << ". " << furnitureDB[i] << "\n";
    }
    std::cout << "How many furniture items do you want to add? ";
    int fCount;
    std::cin >> fCount;

    std::cout << "Enter the numbers of the furniture you want (e.g. 1 3 5): ";
    for (int i = 0; i < fCount; i++) {
        int fChoice;
        std::cin >> fChoice;
        if (fChoice < 1 || (size_t)fChoice > furnitureDB.size()) {
            std::cerr << "Invalid furniture choice, skipping.\n";
            continue;
        }
        prefs.addFurnitureType(furnitureDB[fChoice-1]);
    }

    // 제약사항 입력
    std::cout << "Ensure flow? (y/n): ";
    char flowChar;
    std::cin >> flowChar;
    bool ensureFlow = (flowChar == 'y' || flowChar == 'Y');

    std::cout << "Enter light direction (e.g. east, west, south, north): ";
    std::string lightDir;
    std::cin >> lightDir;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter mandatory furniture alignment description (e.g. 'sofa facing TV'): ";
    std::string mandatoryAlign;
    std::getline(std::cin, mandatoryAlign);

    Constraints cons(ensureFlow, lightDir, mandatoryAlign);

    // 최적화 알고리즘 선택
    std::cout << "Select optimizer (1: Genetic, 2: SimulatedAnnealing): ";
    int optChoice;
    std::cin >> optChoice;
    InteriorOptimizer* opt = nullptr;
    if (optChoice == 2) {
        opt = new SimulatedAnnealingOptimizer();
    } else {
        opt = new GeneticOptimizer();
    }

    Assistant assistant(bInfo, prefs, cons, opt);

    std::ofstream outputFile("output.txt");
    if(!outputFile.is_open()) {
        std::cerr << "Failed to open output.txt\n";
        return 1;
    }

    try {
        assistant.arrangeFurniture();
        outputFile << "Final Furniture Layout:\n";
        for (auto& f : assistant.getPlacedFurnitures()) {
            outputFile << f << "\n";
        }

        StyleRecommender sr;
        auto recs = sr.recommend(prefs.getStyle(), prefs.getColorPalette(), prefs.getBudgetRange().second);
        outputFile << "Style Recommendations:\n";
        for (auto& r : recs) {
            outputFile << "- " << r << "\n";
        }

    } catch (const BudgetExceededException& e) {
        outputFile << "Error: " << e.what() << "\n";
    } catch (const std::exception& ex) {
        outputFile << "Standard Exception: " << ex.what() << "\n";
    } catch (...) {
        outputFile << "Unknown Error Occurred!\n";
    }

    outputFile.close();

    return 0;
}
