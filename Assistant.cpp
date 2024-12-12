#include "Assistant.h"
#include <iostream>
#include <random>  // 랜덤 사용을 위해 추가

Assistant::Assistant(BuildingInfo* bi, const UserPreferences& up, const Constraints& c, InteriorOptimizer* opt)
: buildingInfo(bi), preferences(up), constraints(c), optimizer(opt) {
    // 생성자 구현부
}

Assistant::~Assistant() {
    delete buildingInfo;
    delete optimizer;
}

void Assistant::arrangeFurniture() {
    const auto& wantedFurns = preferences.getFurnitureList();

    // 초기 배치를 랜덤하게 하기 위한 엔진과 분포
    std::default_random_engine eng((std::random_device())());
    // 예: 0~10 범위 내에서 위치를 랜덤하게 지정
    // 필요에 따라 buildingInfo의 shape 치수를 이용하여 범위를 조정할 수도 있음.
    std::uniform_real_distribution<double> distX(0.0, 10.0);
    std::uniform_real_distribution<double> distY(0.0, 10.0);

    for (auto& fName : wantedFurns) {
        double x = distX(eng);
        double y = distY(eng);
        placedFurnitures.add(Furniture(fName, x, y, 0, 1.0, 1.0));
    }

    auto budget = preferences.getBudgetRange();
    double cost = placedFurnitures.size() * 200.0;
    if (cost > budget.second) {
        throw BudgetExceededException();
    }

    // GenericContainer에서 std::vector로 복사
    std::vector<Furniture> tempFurn = placedFurnitures.getItems(); 
    optimizer->optimize(tempFurn); // 최적화 알고리즘 호출

    // 최적화 결과 반영
    GenericContainer<Furniture> newContainer;
    for (auto &f : tempFurn) {
        newContainer.add(f);
    }
    placedFurnitures = newContainer;
}
