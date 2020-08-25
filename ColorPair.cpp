#include<iostream>
#include <assert.h>
#include "ColorPair.h"

using namespace TelCoColorCoder;

numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

    ColorPair::ColorPair(MajorColor major, MinorColor minor) : 
        majorColor(major), minorColor(minor) {};
    MajorColor ColorPair::getMajor() {
        return majorColor;
        }
    MinorColor ColorPair::getMinor() {
        return minorColor;
        }
    std::string ColorPair::ToString() {
            std::string colorPairStr = MajorColorNames[majorColor];
            colorPairStr += " ";
            colorPairStr += MinorColorNames[minorColor];
            return colorPairStr;
        }
    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = 
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }
    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }
