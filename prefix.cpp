#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePrefix(string expression) {
    stack<int> operandStack;

    for (int i = expression.length() - 1; i >= 0; i--) {
        char c = expression[i];
        if (isdigit(c)) {
            operandStack.push(c - '0');
        } else {
            int operand1 = operandStack.top();
            operandStack.pop();
            int operand2 = operandStack.top();
            operandStack.pop();
            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    result = 0;
            }
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int main() {
    string expression;
    cout << "Enter a prefix expression: ";
    getline(cin, expression);
    int result = evaluatePrefix(expression);
    cout << "Result: " << result << endl;
    return 0;
}
