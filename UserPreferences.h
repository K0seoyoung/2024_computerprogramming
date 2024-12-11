#ifndef USERPREFERENCES_H
#define USERPREFERENCES_H

#include <string>
#include <vector>

class UserPreferences {
private:
    std::string style;
    std::string colorPalette;
    std::vector<std::string> furnitureList; 
    double budgetMin, budgetMax;

public:
    UserPreferences(const std::string& st="", const std::string& cp="", double bMin=0.0, double bMax=10000.0)
    : style(st), colorPalette(cp), budgetMin(bMin), budgetMax(bMax) {}

    void setStyle(const std::string& s);
    void setColorPalette(const std::string& c);
    void setBudgetRange(double minB, double maxB);
    void addFurnitureType(const std::string& f);

    std::string getStyle() const;
    std::string getColorPalette() const;
    std::pair<double,double> getBudgetRange() const;
    const std::vector<std::string>& getFurnitureList() const;
};

#endif
