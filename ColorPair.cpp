#include "ColorPair.h"

using namespace TelCoColorCoder;

    ColorPair::ColorPair(MajorColor major, MinorColor minor) : 
        majorColor(major), minorColor(minor) {};
    MajorColor ColorPair::getMajor() {
        return majorColor;
        }
    MinorColor ColorPair::getMinor() {
        return minorColor;
        }
    std::string ColorPair::ToString() {
            std::string colorPairStr = MajorColorNames[MajorColor::majorColor];
            colorPairStr += " ";
            colorPairStr += MinorColorNames[MinorColor::minorColor];
            return colorPairStr;
        }

    ColorPair ColorPair::GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = 
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }
    int ColorPair::GetPairNumberFromColor(MajorColor major, MinorColor minor) {
          return major * numberOfMinorColors + minor + 1;
    }
