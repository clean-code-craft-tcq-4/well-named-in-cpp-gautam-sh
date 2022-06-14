#ifndef TELCO_COLOR_CODER_HPP
#define TELCO_COLOR_CODER_HPP

#include <iostream>

namespace TelCoColorCoder
{
    enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
    enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

    const char* MajorColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet"
    };
    int numberOfMajorColors =
        sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const char* MinorColorNames[] = {
        "Blue", "Orange", "Green", "Brown", "Slate"
    };
    int numberOfMinorColors =
        sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    class ColorPair {
        private:
            MajorColor majorColor;
            MinorColor minorColor;
        public:
            ColorPair(MajorColor major, MinorColor minor):
                majorColor(major), minorColor(minor)
            {}
            MajorColor getMajor() {
                return majorColor;
            }
            MinorColor getMinor() {
                return minorColor;
            }
            std::string ToString() {
                std::string colorPairStr = MajorColorNames[majorColor];
                colorPairStr += " ";
                colorPairStr += MinorColorNames[minorColor];
                return colorPairStr;
            }
    };

    ColorPair GetColorFromPair(int);
    int GetPairFromColor(MajorColor, MinorColor);
    
}

// void testNumberToPair(int pairNumber,
//     TelCoColorCoder::MajorColor expectedMajor,
//     TelCoColorCoder::MinorColor expectedMinor)
// {
//     TelCoColorCoder::ColorPair colorPair =
//         TelCoColorCoder::GetColorFromPairNumber(pairNumber);
//     std::cout << "Got pair " << colorPair.ToString() << std::endl;
//     assert(colorPair.getMajor() == expectedMajor);
//     assert(colorPair.getMinor() == expectedMinor);
// }

// void testPairToNumber(
//     TelCoColorCoder::MajorColor major,
//     TelCoColorCoder::MinorColor minor,
//     int expectedPairNumber)
// {
//     int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
//     std::cout << "Got pair number " << pairNumber << std::endl;
//     assert(pairNumber == expectedPairNumber);
// }



#endif
