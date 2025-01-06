#include <string>
#include <cmath>
#include <stack>
#include <iostream>
#include <cctype>
#include <cstdlib>

#include "gai2.h"

#include <vector>

int main() {
    // 测试表达式
    std::vector<std::string> test_cases = {
        "4.04-2.87*3.92-0.48", // 测试用例
        "3+5",
        "10-2*3",
        "(1+2)*3",
        "5+(2-1)",
        "2*(2+3*(1+2))",
        "1.1*2+3",
        "0.7+0.6",
        "1+(-1)",
        "(-2)/1+3",
        "3*((-2)*3+1)",
        "(2+3)))",
        "(1+2", 
        "((2)",
        "1++2",
        "*3+5",
        "-2*3",
        "(2+3)*4",
        "2@3",
        "10/(5-5)", 
    };

    for (const auto& test_case : test_cases) {
        std::cout << "Testing expression: " << test_case << std::endl;
        evaluate_expression(test_case);
        std::cout << std::endl;
    }

    return 0;
}
