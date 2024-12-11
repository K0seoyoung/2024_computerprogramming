#ifndef ASSISTANT_H
#define ASSISTANT_H

#include "BuildingInfo.h"
#include "UserPreferences.h"
#include "Constraints.h"
#include "Furniture.h"
#include "InteriorOptimizer.h"
#include "StyleRecommender.h"
#include <vector>
#include <exception>

// 예외 클래스
class BudgetExceededException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Budget limit exceeded.";
    }
};

class Assistant {
private:
    BuildingInfo* buildingInfo;
    UserPreferences preferences;
    Constraints constraints;
    InteriorOptimizer* optimizer; // 다형성 활용
    StyleRecommender styleRec;

    std::vector<Furniture> placedFurnitures;
public:
    Assistant(BuildingInfo* bi, const UserPreferences& up, const Constraints& c, InteriorOptimizer* opt);
    ~Assistant();

    void arrangeFurniture();
    void printResult();
};

#endif
