#include "StyleRecommender.h"

std::vector<std::string> StyleRecommender::recommend(const std::string& style) {
    // 단순한 예시
    return {"Base Color: White", "Texture: Wood"};
}

std::vector<std::string> StyleRecommender::recommend(const std::string& style, const std::string& colorPalette) {
    return {"Color Palette: " + colorPalette, "Texture: Marble"};
}

std::vector<std::string> StyleRecommender::recommend(const std::string& style, const std::string& colorPalette, double budget) {
    if(budget < 1000) {
        return {"Low-budget recommendation: Use simple vinyl flooring."};
    }
    return {"High-end recommendation: Use premium hardwood flooring."};
}
