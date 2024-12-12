#include "InteriorOptimizer.h"
#include <iostream>
#include <random>

void GeneticOptimizer::optimize(std::vector<Furniture>& furnitures) {
    std::cout << "[GeneticOptimizer] Running genetic optimization...\n";
    // 실제 유전 알고리즘 구현 대신, 여기서는 아무 것도 하지 않거나,
    // 가구를 약간 움직이는 더미 로직을 넣을 수 있습니다.
    // 일단은 그대로 둡니다.
}

void SimulatedAnnealingOptimizer::optimize(std::vector<Furniture>& furnitures) {
    std::cout << "[SimulatedAnnealingOptimizer] Running simulated annealing optimization...\n";
    // 단순히 가구 위치를 약간 랜덤하게 변화시키는 더미 로직
    std::default_random_engine eng((std::random_device())());
    std::uniform_real_distribution<double> dist(-0.5, 0.5);
    for (auto &f : furnitures) {
        double newX = f.getX() + dist(eng);
        double newY = f.getY() + dist(eng);
        f.setPosition(newX, newY);
    }
}
