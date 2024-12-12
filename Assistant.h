#ifndef ASSISTANT_H
#define ASSISTANT_H

#include "BuildingInfo.h"
#include "UserPreferences.h"
#include "Constraints.h"
#include "Furniture.h"
#include "InteriorOptimizer.h"
#include "StyleRecommender.h"
#include "GenericContainer.h"
#include <vector>
#include <exception>

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
    InteriorOptimizer* optimizer; 
    StyleRecommender styleRec;

    GenericContainer<Furniture> placedFurnitures;  // 가구 컨테이너

public:
    Assistant(BuildingInfo* bi, const UserPreferences& up, const Constraints& c, InteriorOptimizer* opt);
    ~Assistant();

    void arrangeFurniture();
    // 기존 printResult()는 파일출력을 main에서 하기로 했으므로 선택적으로 주석처리 가능
    // void printResult();

    // placedFurnitures를 외부에서 접근할 수 있도록 하는 함수 추가
    const std::vector<Furniture>& getPlacedFurnitures() const {
        return placedFurnitures.getItems();
    }
};

#endif
