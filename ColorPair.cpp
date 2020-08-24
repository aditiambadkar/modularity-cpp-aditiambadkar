#include "ColorPair.h"

using namespace TelCoColorCoder;
using namespace std;

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

void testNumberToPair(int pairNumber, TelCoColorCoder::MajorColor expectedMajor, TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}
