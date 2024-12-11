#include <memory>
#include <iostream>

#include "../headerFile/RectangleShape.h"
#include "../headerFile/Style.h"
#include "../headerFile/InteriorDesignAssistant.h"
#include "../headerFile/GeneticAlgorithm.h"
#include "../headerFile/Sofa.h"
#include "../headerFile/Table.h"
#include "../headerFile/Exceptions.h"

int main() {
    try {
        std::unique_ptr<Shape> shape(new RectangleShape(10, 12));
        Style userStyle("Pastel Palette", "Wood & Cotton");
        InteriorDesignAssistant assistant(std::move(shape), userStyle, 2000.0);

        assistant.setAlgorithm(new GeneticAlgorithm());
        assistant.addFurniture(new Sofa());
        assistant.addFurniture(new Table());
        assistant.addFurniture(new Sofa());

        assistant.arrangeFurniture();
        assistant.printResult();

    } catch (const BudgetExceededException& e) {
        std::cerr << "Error: " << e.what() << "\n";
    } catch (const InvalidPlacementException& e) {
        std::cerr << "Error: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Unhandled exception: " << e.what() << "\n";
    }

    return 0;
}
