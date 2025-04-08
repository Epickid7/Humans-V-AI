//
// Created by Kyle Parker on 4/6/25.
//

#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>

#include "SFML/Graphics/Font.hpp"

enum class AssetType {
    Font,
    Audio,
    Image
};

enum class FontStyle {
    Black,
    BlackItalic,
    Bold,
    BoldItalic,
    Heavy,
    HeavyItalic,
    Light,
    LightItalic,
    Medium,
    MediumItalic,
    Regular,
    Italic,
    SemiBold,
    SemiBoldItalic,
    Thin,
    ThinItalic,
    UltraLight,
    UltraLightItalic,
};

class Utilities {
public:

    static std::string getAssetPath(const AssetType &type, const std::string &name);

    static sf::Font getAttributedFont(const FontStyle &style, const std::string &font);

    // Keep adding here!

private:

    static std::string getStyleName(const FontStyle &style);

    // Keep adding here! If the developer does not need to call the function, place them here.
};



#endif //UTILITIES_H
