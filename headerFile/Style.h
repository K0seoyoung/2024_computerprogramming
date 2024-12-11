#ifndef STYLE_H
#define STYLE_H

#include <string>

class Style {
private:
    std::string colorPalette;
    std::string material;
public:
    Style(const std::string& c, const std::string& m);
    void print() const;
};

#endif
