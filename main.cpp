#include <iostream>
#include "Assistant.h"
#include "Shape.h"
#include "BuildingInfo.h"
#include "UserPreferences.h"
#include "Constraints.h"
#include "InteriorOptimizer.h"
#include <string>

int main() {
    // 사용자 입력 받기
    std::string shapeType;
    std::cout << "Select house shape (circle, rectangle, triangle): ";
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

    // 문, 창문 한 개씩만 입력 받는 예제 (필요시 반복문으로 확장 가능)
    double dx, dy;
    std::cout << "Enter door position (x y): ";
    std::cin >> dx >> dy;
    bInfo->addDoor(dx, dy);

    double wx, wy;
    std::cout << "Enter window position (x y): ";
    std::cin >> wx >> wy;
    bInfo->addWindow(wx, wy);

    // 사용자 선호 입력
    std::string style, colorPalette;
    double budgetMin, budgetMax;
    std::cout << "Enter interior style: ";
    std::cin >> style;
    std::cout << "Enter color palette: ";
    std::cin >> colorPalette;
    std::cout << "Enter budget range (min max): ";
    std::cin >> budgetMin >> budgetMax;

    UserPreferences prefs(style, colorPalette, budgetMin, budgetMax);

    // 필요 가구 목록 입력 (예시: 3개)
    int furnitureCount = 3;
    std::cout << "Enter " << furnitureCount << " furniture types (e.g. Sofa TV Table): ";
    for (int i = 0; i < furnitureCount; i++) {
        std::string fName;
        std::cin >> fName;
        prefs.addFurnitureType(fName);
    }

    // 제약 조건 입력
    char flowChar;
    std::cout << "Ensure flow? (y/n): ";
    std::cin >> flowChar;
    bool ensureFlow = (flowChar == 'y' || flowChar == 'Y');

    std::string lightDir;
    std::cout << "Enter light direction (e.g. east, west, south, north): ";
    std::cin >> lightDir;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼 정리
    std::string mandatoryAlign;
    std::cout << "Enter mandatory furniture alignment description (e.g. 'sofa facing TV'): ";
    std::getline(std::cin, mandatoryAlign);

    Constraints cons(ensureFlow, lightDir, mandatoryAlign);

    // 최적화 알고리즘 선택 (사용자 선택)
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

    try {
        assistant.arrangeFurniture();
        assistant.printResult();
    } catch (const BudgetExceededException& e) {
        std::cerr << "Error: " << e.what() << "\n";
    } catch (const std::exception& ex) {
        std::cerr << "Standard Exception: " << ex.what() << "\n";
    } catch (...) {
        std::cerr << "Unknown Error Occurred!\n";
    }

    return 0;
}
