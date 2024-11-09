#include <iostream>
#include <stack>
#include <string>

using namespace std;

// ��������������ȼ�
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// ��������׺���ʽת��Ϊ��׺���ʽ
string infixToPostfix(const string& infix) {
    stack<char> operators;  // ���ڴ洢��������ջ
    string postfix;  // ���յĺ�׺���ʽ

    // ������׺���ʽ�е�ÿ���ַ�
    for (char ch : infix) {
        // ����ǲ���������ĸ����ֱ����ӵ���׺���ʽ
        if (isalpha(ch)) {
            postfix += ch;
        }
        // ����������ţ�ѹ��ջ��
        else if (ch == '(') {
            operators.push(ch);
        }
        // ����������ţ�������������в�������ֱ������������
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // ����������
        }
        // ����������
        else {
            // ����ջ�����ȼ��߻���ȵĲ�����
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);  // ����ǰ������ѹ��ջ
        }
    }

    // ��ջ��ʣ��Ĳ��������ε�������ӵ���׺���ʽ
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;  // ���غ�׺���ʽ
}

int main() {
    string infix;
    cout << "��������׺���ʽ: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "��Ӧ�ĺ�׺���ʽ: " << postfix << endl;

    return 0;
}
