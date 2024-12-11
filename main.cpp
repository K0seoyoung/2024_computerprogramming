#include <iostream>
#include "Assistant.h"
#include "Shape.h"
#include "BuildingInfo.h"
#include "UserPreferences.h"
#include "Constraints.h"
#include "InteriorOptimizer.h"

int main() {
    // 건물 형태: 사각형
    Shape* rect = new Rectangle(10.0, 8.0);
    BuildingInfo* bInfo = new BuildingInfo(rect);
    bInfo->addDoor(1.0, 0.0);
    bInfo->addWindow(5.0, 8.0);

    UserPreferences prefs("modern", "blue-white", 0, 5000);
    prefs.addFurnitureType("Sofa");
    prefs.addFurnitureType("TV");
    prefs.addFurnitureType("Table");

    Constraints cons(true, "east", "sofa facing TV");

    InteriorOptimizer* opt = new GeneticOptimizer(); // 또는 new SimulatedAnnealingOptimizer();

    Assistant assistant(bInfo, prefs, cons, opt);

    try {
        assistant.arrangeFurniture();
        assistant.printResult();
    } catch (const BudgetExceededException& e) {
        std::cerr << "Error: " << e.what() << "\n";
    } catch (...) {
        std::cerr << "Unknown Error Occurred!\n";
    }

    return 0;
}
