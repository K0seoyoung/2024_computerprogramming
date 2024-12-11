#ifndef STYLERECOMMENDER_H
#define STYLERECOMMENDER_H

#include <string>
#include <vector>

// 함수 중복(오버로딩) 예시
class StyleRecommender {
public:
    std::vector<std::string> recommend(const std::string& style);
    std::vector<std::string> recommend(const std::string& style, const std::string& colorPalette);
    std::vector<std::string> recommend(const std::string& style, const std::string& colorPalette, double budget);
};

#endif
