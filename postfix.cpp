#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string expression) {
    stack<int> operandStack;

    for (char c : expression) {
        if (isdigit(c)) {
            operandStack.push(c - '0');
        } else {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
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
    cout << "Enter a postfix expression: ";
    getline(cin, expression);
    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;
    return 0;
}
