#include "d02.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include "utils.h"

struct Line {
    Line(const std::string& line) {
        char pw[100];
        std::sscanf(line.c_str(), "%d-%d %c: %99s", &policy_num1, &policy_num2, &policy_letter, pw);
        password = { pw };
    }
    bool pw_is_valid_first() const {
        int count;
        count = std::count(password.begin(), password.end(), policy_letter);
        return policy_num1 <= count && count <= policy_num2;
    }
    bool pw_is_valid_second() const {
        return (password[policy_num1 - 1] == policy_letter) ^ (password[policy_num2 - 1] == policy_letter);
    }
    int policy_num1{};
    int policy_num2{};
    char policy_letter{};
    std::string password{};
};

bool getInput(std::string fileName, std::vector<Line>& input) {
    std::vector<std::string> vecOfStr;
    auto result = getFileContent(fileName, vecOfStr);
    if (result) {
        std::transform(vecOfStr.begin(), vecOfStr.end(), std::back_inserter(input),
            [](const std::string& str) -> Line { return Line{ str }; });
    }
    return result;
}


int d02_first_half() {
    std::vector<Line> input;
    auto result = getInput("d02input.txt", input);
    auto count{ 0 };

    return std::count_if(input.begin(), input.end(),
        [](const Line& l)->bool {return l.pw_is_valid_first(); });
}

int d02_second_half()
{
    std::vector<Line> input;
    auto result = getInput("d02input.txt", input);
  
    return std::count_if(input.begin(), input.end(),
        [](const Line& l)->bool {return l.pw_is_valid_second(); });;
}
