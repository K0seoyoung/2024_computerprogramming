#include "Assistant.h"
#include <iostream>

Assistant::Assistant(BuildingInfo* bi, const UserPreferences& up, const Constraints& c, InteriorOptimizer* opt)
: buildingInfo(bi), preferences(up), constraints(c), optimizer(opt) {}

Assistant::~Assistant() {
    delete buildingInfo;
    delete optimizer;
}

void Assistant::arrangeFurniture() {
    // 가구 리스트 생성(여기서는 단순화)
    const auto& wantedFurns = preferences.getFurnitureList();
    for (auto& fName : wantedFurns) {
        placedFurnitures.push_back(Furniture(fName, 0,0,0));
    }

    // 예산 체크 (예시로 예산 범위 내에서 가구 배치)
    auto budget = preferences.getBudgetRange();
    double cost = (double)placedFurnitures.size() * 200.0; // 단순하게 가구당 200원 가정
    if (cost > budget.second) {
        throw BudgetExceededException();
    }

    // 최적화 프로세스 실행
    optimizer->optimize(placedFurnitures);
}

void Assistant::printResult() {
    std::cout << "Final Furniture Layout:\n";
    for (auto& f : placedFurnitures) {
        std::cout << f << "\n";
    }

    // 스타일 추천 (함수 오버로딩 사용)
    auto recs = styleRec.recommend(preferences.getStyle(), preferences.getColorPalette(), preferences.getBudgetRange().second);
    std::cout << "Style Recommendations:\n";
    for (auto& r : recs) {
        std::cout << "- " << r << "\n";
    }
}
