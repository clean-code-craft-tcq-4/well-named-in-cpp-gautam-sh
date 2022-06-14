#include <assert.h>
#include "telco_color_coder.hpp"

namespace TelCoColorCoder
{
    ColorPair GetColorFromPair(int pair) {
        int zeroBasedPair = pair - 1;
        MajorColor majorColor = 
            (MajorColor)(zeroBasedPair / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPair % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }
    int GetPairFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }
}

void testNumberToPair(int pair,
TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPair(pair);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPair)
{
    int pair = TelCoColorCoder::GetPairFromColor(major, minor);
    std::cout << "Got pair number " << pair << std::endl;
    assert(pair == expectedPair);
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    return 0;
}
