#include "d03.h"
#include "utils.h"
#include <iostream>
#include <algorithm>

using map = std::vector<std::vector<bool>>;

bool getInput(std::string fileName, map& input) {
    std::vector<std::string> vecOfStr;
    auto result = getFileContent(fileName, vecOfStr);
    if (result) {
        std::transform(vecOfStr.begin(), vecOfStr.end(), std::back_inserter(input),
            [](const std::string& str) -> std::vector<bool> { 
                int pattern_width = str.length();
                std::vector<bool> line(pattern_width);
                for (size_t i = 0; i < pattern_width; i++)
                    line[i] = str[i] == '#';
                return line; });
    }
    return result;
}

// The pattern map of the problem can be projected on cilindrical discrete plane
// where cilinder's height and perimeter are respectively pattern_height and pattern_width.
// The movement happens on a line on a discrete plane.
// The equation for a line starting at (0,0) in a cilindrical semi-infinite discrete plane is
// x = y * slope mod cilinder_perimeter where x, y are integers, slope is a rational and 
// y * slope is rounded to the nearest integer.
// In our case slope = slope_right / slope_down and the path is not this line
// but only the dots on this line with vertical coordinate multiple of down_slope (jumping).

int d03_first_half() {
    map input;
    auto result = getInput("d03input.txt", input);

    auto slope_right{ 3 };
    auto slope_down{ 1 };
    auto pattern_width{ input[0].size() };
    auto pattern_height{ input.size() };
    int count{ 0 };
    for (size_t y = 0; y < pattern_height; y += slope_down)
        if (input[y][(y * slope_right / slope_down) % pattern_width]) count++;
    
    return count;
}

unsigned int d03_second_half()
{
    map input;
    auto result = getInput("d03input.txt", input);

    int slope_right[]{ 1,3,5,7,1 };
    int slope_down[]{ 1,1,1,1,2 };
    auto pattern_width{ input[0].size() };
    auto pattern_height{ input.size() };
    int count[]{ 0,0,0,0,0, };
    for (size_t i = 0; i < 5; i++)
        for (size_t y = 0; y < pattern_height; y += slope_down[i])
            if (input[y][(y * slope_right[i] / slope_down[i]) % pattern_width]) count[i]++;

    unsigned int answer{ 1 };
    for (auto& c : count)
        answer *= c;

    return answer;
}
