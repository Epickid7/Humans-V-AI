//
// Created by Kyle Parker on 4/6/25.
//

#include "Utilities.h"

#include "SFML/Graphics/Font.hpp"
#include "SFML/System/Exception.hpp"

/// Written by Kyle Parker on Apr 6, 2025
/// @param type The type of asset (Image, Audio, Font) for which the path is being requested.
/// @param name The name of the asset file.
/// @return The full path to the asset of a known type; otherwise, returns an empty string.
std::string Utilities::getAssetPath(const AssetType &type, const std::string &name) {
    switch (type) {
        case AssetType::Image:
            return ASSETS_PATH "/images/" + name;
        case AssetType::Audio:
            return ASSETS_PATH "/audio/" + name;
        case AssetType::Font:
            return ASSETS_PATH "/fonts/" + name;
        default:
            return "";
    }
}

/// Written by Kyle Parker on Apr 6, 2025
/// @param style The style of the font to be used.
/// @param font The base name of the font.
/// @return The full path to the attributed font asset.
sf::Font Utilities::getAttributedFont(const FontStyle &style, const std::string &font) {
    sf::Font loadedFont;

    const std::string path = getAssetPath(AssetType::Font,font + "-" + getStyleName(style));

    // Attempt to load otf type
    if (!loadedFont.openFromFile(path + ".otf")) {
        // Failed to load otf, now attempt ttf
        if (!loadedFont.openFromFile(path + ".ttf")) {
            // Failed to open otf and ttf
            throw sf::Exception("Failed to open the file or the type is not supported.");
        }
    }

    return loadedFont;
}

// MARK: - Private

/// Written by Kyle Parker on Apr 6, 2025
/// @param style The font style for which the name is requested.
/// @return The name of the font style as a string; returns an empty string for unknown styles.
std::string Utilities::getStyleName(const FontStyle &style) {
    switch (style) {
        case FontStyle::Black:
            return "Black";
        case FontStyle::BlackItalic:
            return "BlackItalic";
        case FontStyle::Bold:
            return "Bold";
        case FontStyle::BoldItalic:
            return "BoldItalic";
        case FontStyle::Heavy:
            return "Heavy";
        case FontStyle::HeavyItalic:
            return "HeavyItalic";
        case FontStyle::Light:
            return "Light";
        case FontStyle::LightItalic:
            return "LightItalic";
        case FontStyle::Medium:
            return "Medium";
        case FontStyle::MediumItalic:
            return "MediumItalic";
        case FontStyle::Regular:
            return "Regular";
        case FontStyle::Italic:
            return "Italic";
        case FontStyle::SemiBold:
            return "SemiBold";
        case FontStyle::SemiBoldItalic:
            return "SemiBoldItalic";
        case FontStyle::Thin:
            return "Thin";
        case FontStyle::ThinItalic:
            return "ThinItalic";
        case FontStyle::UltraLight:
            return "UltraLight";
        case FontStyle::UltraLightItalic:
            return "UltraLightItalic";
        default:
            return "";
    }
}
