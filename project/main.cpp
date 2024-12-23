#include "expression_evaluator.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    // 预定义的测试表达式
    std::vector<std::string> test_cases = {
        //四则运算
        "3+5",
        //优先级
        "10-2*3",
        //处理括号
        "(1+2)*3",
        "(4/2)+(3*2)",
        "5+(2-1)",
        "2*(2+3*(1+2))",
        //处理小数
        "1.1*2+3",
        "0.7+0.6",
        //处理负数
        "1+(-1)",
        "(-2)/1+3",
        "3*((-2)*3+1)",
        //异常情况
        //除数为0
        "10/(5-5)", 
        //括号不匹配
        "(1+2", 
        "((2)",
        //连续使用运算符
        "1++2",     
        //开头是运算符
        "*3+5",
        "-2*3",//这种情况合法因为处理了负数；
        "(2+3)*4",//左括号开头合法
        //出现其他符号
        "2@3"


        
    };

    // 逐个测试每个表达式
    for (const auto& test_case : test_cases) {
        std::cout << "Testing expression: " << test_case << std::endl;
        evaluate_expression(test_case); // 调用函数计算并输出结果
        std::cout << std::endl; // 输出换行以便于阅读
    }

    return 0;
}