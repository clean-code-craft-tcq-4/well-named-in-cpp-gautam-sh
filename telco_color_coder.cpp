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