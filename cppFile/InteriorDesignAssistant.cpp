#include <iostream>
#include <cmath>

#include "../headerFile/InteriorDesignAssistant.h"
#include "../headerFile/RectangleShape.h"
#include "../headerFile/CircleShape.h"

InteriorDesignAssistant::InteriorDesignAssistant(std::unique_ptr<Shape> shape, const Style& s, double b)
    : buildingShape(std::move(shape)), style(s), budget(b) 
{
    if (auto rect = dynamic_cast<RectangleShape*>(buildingShape.get())) {
        roomWidth = std::sqrt(rect->getArea());
        roomHeight = std::sqrt(rect->getArea());
    } else if (auto cir = dynamic_cast<CircleShape*>(buildingShape.get())) {
        double area = cir->getArea();
        roomWidth = std::sqrt(area);
        roomHeight = std::sqrt(area);
    } else {
        roomWidth = 10.0; 
        roomHeight = 10.0;
    }
}

void InteriorDesignAssistant::setAlgorithm(OptimizationAlgorithm* alg) {
    optimizer.reset(alg);
}

void InteriorDesignAssistant::addFurniture(Furniture* f) {
    furnitures.add(f);
}

void InteriorDesignAssistant::arrangeFurniture() {
    if (optimizer) {
        optimizer->run();
    }

    double xPos = 0;
    double yPos = 0;
    for (auto f : furnitures.getItems()) {
        f->setPosition(xPos, yPos);
        xPos += 2.0; 
        if (xPos > roomWidth) {
            xPos = 0;
            yPos += 2.0;
        }
        if (!f->isPlacementValid(roomWidth, roomHeight)) {
            throw InvalidPlacementException("가구가 방 범위를 벗어남");
        }
    }

    double cost = furnitures.getItems().size() * 100.0;
    if (cost > budget) {
        throw BudgetExceededException("예산 초과!");
    }
}

void InteriorDesignAssistant::printResult() const {
    std::cout << "===== Final Interior Design Result =====\n";
    buildingShape->printInfo();
    style.print();
    for (auto f : furnitures.getItems()) {
        f->print();
    }
}
