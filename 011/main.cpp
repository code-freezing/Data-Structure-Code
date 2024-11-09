#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 定义运算符的优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 函数将中缀表达式转换为后缀表达式
string infixToPostfix(const string& infix) {
    stack<char> operators;  // 用于存储操作符的栈
    string postfix;  // 最终的后缀表达式

    // 遍历中缀表达式中的每个字符
    for (char ch : infix) {
        // 如果是操作数（字母），直接添加到后缀表达式
        if (isalpha(ch)) {
            postfix += ch;
        }
        // 如果是左括号，压入栈中
        else if (ch == '(') {
            operators.push(ch);
        }
        // 如果是右括号，弹出并添加所有操作符，直到遇到左括号
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // 弹出左括号
        }
        // 如果是运算符
        else {
            // 弹出栈中优先级高或相等的操作符
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);  // 将当前操作符压入栈
        }
    }

    // 将栈中剩余的操作符依次弹出并添加到后缀表达式
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;  // 返回后缀表达式
}

int main() {
    string infix;
    cout << "请输入中缀表达式: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "对应的后缀表达式: " << postfix << endl;

    return 0;
}
