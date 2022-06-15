#include "telco_color_coder.hpp"
#include <map>

std::map<std::string, int> generateColorCodingManual() {
    std::map<std::string, int> color_coding_manual;

    for(int i=1; i <= 25; ++i)
    {
        color_coding_manual[TelCoColorCoder::GetColorFromPair(i).ToString()] = i;
    }
    return color_coding_manual;
}