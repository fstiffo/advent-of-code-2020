#include "d01.h"
#include "utils.h"
#include <iostream>
#include <algorithm>

bool getInput(std::string fileName, std::vector<int>& input) {
    std::vector<std::string> vecOfStr;
    auto result = getFileContent("d01input.txt", vecOfStr);
    if (result) {
        std::transform(vecOfStr.begin(), vecOfStr.end(), std::back_inserter(input),
            [](const std::string& str) -> int { return std::stoi(str); });
    }
    return result;
}

int d01_first_half()
{
    std::vector<int> input;
    auto result = getInput("d01input.txt", input);

    if (result) {
        const auto size = input.size();
        for (auto first = 0; first < size - 1; first++)
            for (auto second = first + 1; second < size; second++)
                if (input[first] + input[second] == 2020) return input[first] * input[second];
    }
    return -1;
}

int d01_second_half()
{
    std::vector<int> input;
    auto result = getInput("d01input.txt", input);

    if (result) {
        const auto size = input.size();
        for (auto first = 0; first < size - 2; first++)
            for (auto second = first + 1; second < size - 1; second++)
                for (auto third = second + 1; third < size; third++)
                    if (input[first] + input[second] + input[third] == 2020) return input[first] * input[second] * input[third];
    }
    return -1;
}
