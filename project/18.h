#include<string>
#include<cmath>
#include<stack>
#include<iostream>
#include<cctype>



// 优先级函数
int priority(char op) {
    switch(op) {
        case '*':
        case '/':
            return 2;
        case '-':
        case '+':
            return 1;
        default:
            return 0;
    }
}

// 计算函数
double calculate(char op, std::stack<double>& nums) {
    if (nums.size() < 2) {
        std::cout << "ILLEGAL1" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    double b = nums.top();
    nums.pop();
    double a = nums.top();
    nums.pop();

    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                std::cout << "ILLEGAL2" << std::endl;
                std::exit(EXIT_FAILURE);
            }
            return a / b;
        default:
            return 0;
    }
}

// 表达式求值函数
void evaluate_expression(const std::string& ss) {
    std::string string1;
    if (ss.empty()) return;

    // 输入合法性检查
    if (ss[0] == '+' || ss[0] == '/' || ss[0] == '*' || ss[0] == ')') {
        std::cout << "ILLEGAL3" << std::endl;
        return;
    }

    for (int i = 0; i < ss.length(); i++) {
        if ((ss[i] == '+' || ss[i] == '-' || ss[i] == '*' || ss[i] == '/') &&
            (ss[i + 1] == '+' || ss[i + 1] == '-' || ss[i + 1] == '*' || ss[i + 1] == '/')) {
            std::cout << "ILLEGAL4" << std::endl;
            return;
        }
        if ((!isdigit(ss[i])) && (ss[i] != '+') && (ss[i] != '-') && (ss[i] != '*') && (ss[i] != '/') && 
            (ss[i] != '(') && (ss[i] != ')') && (ss[i] != '.')) {
            std::cout << "ILLEGAL5" << std::endl;
            return;
        }
    }

    // 括号合法性检查
    int nl = 0, nr = 0;
    for (int i = 0; i < ss.length(); i++) {
        if (ss[i] == '(') nl++;
        if (ss[i] == ')') nr++;
    }
    if (nr != nl) {
        std::cout << "ILLEGAL6" << std::endl;
        return;
    }

    // 替换负号为“0-”处理负数
    string1 = "";
    for (int i = 0; i < ss.length(); i++) {
        if (ss[i] == '-' &&ss[i-1] != ')'&& (i == 0 || !isdigit(ss[i - 1]))) {
            string1 += "0-";
        } else {
            string1 += ss[i];
        }
    }

    int i = 0;
    std::stack<double> nums;
    std::stack<char> ops;

    while (i < string1.length()) {
        std::string in1 = "";
        while (isdigit(string1[i]) || string1[i] == '.') {
            in1 += string1[i];
            i++;
        }

        if (in1 != "") {
            double num = std::stod(in1);
            nums.push(num);
            //std::cout<<"num:"<<nums.top()<<std::endl;
        }

        // 处理操作符
        if (i < string1.length() && (string1[i] == '+' || string1[i] == '-' || string1[i] == '*' || string1[i] == '/')) {
            while (!ops.empty() && priority(string1[i]) <= priority(ops.top())) {
                double result = calculate(ops.top(), nums);
                nums.push(result);
                ops.pop();
            }
            ops.push(string1[i]);
            i++;
        }

        // 处理括号
        if (i < string1.length() && string1[i] == '(') {
            ops.push('(');
            i++;
        }
        if (i < string1.length() && string1[i] == ')') {
            while (ops.top() != '(') {
                double result = calculate(ops.top(), nums);
                nums.push(result);
                ops.pop();
            }
            ops.pop(); // 移除 '('
            i++;
        }
    }

    // 计算栈中剩余的运算符
    while (!ops.empty()) {
        double result = calculate(ops.top(), nums);
        nums.push(result);
        ops.pop();
    }

    // 输出结果
    if (!nums.empty()) {
        std::cout << "result: " << nums.top() << std::endl;
    } else {
        std::cout << "ILLEGAL7" << std::endl;
    }
}
