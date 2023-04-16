#include <iostream>
#include <stack>
#include <string>
using namespace std;

// utility function to check if a given character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// utility function to perform an operation on two operands
int performOperation(char operation, int operand1, int operand2) {
    if (operation == '+') return operand1 + operand2;
    else if (operation == '-') return operand1 - operand2;
    else if (operation == '*') return operand1 * operand2;
    else if (operation == '/') return operand1 / operand2;
    else {
        cout << "Unexpected operator: " << operation << endl;
        return -1;
    }
}

// function to evaluate an infix expression and return its value
int evaluateInfix(string expression) {
    stack<int> operands;
    stack<char> operators;

    for (int i = 0; i < expression.length(); i++) {
        // ignore whitespace
        if (expression[i] == ' ') continue;

        // if the current character is an opening parenthesis, push it onto the operators stack
        else if (expression[i] == '(') operators.push(expression[i]);

        // if the current character is a digit, push the whole number onto the operands stack
        else if (isdigit(expression[i])) {
            int operand = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            operands.push(operand);
        }

        // if the current character is an operator, process it according to the precedence rules
        else if (isOperator(expression[i])) {
            while (!operators.empty() && operators.top() != '(' && ((expression[i] != '*' && expression[i] != '/') || (operators.top() != '+' && operators.top() != '-'))) {
                int operand2 = operands.top(); operands.pop();
                int operand1 = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                int result = performOperation(op, operand1, operand2);
                operands.push(result);
            }
            operators.push(expression[i]);
        }

        // if the current character is a closing parenthesis, process all operators until the matching opening parenthesis is found
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int operand2 = operands.top(); operands.pop();
                int operand1 = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                int result = performOperation(op, operand1, operand2);
                operands.push(result);
            }
            operators.pop();
        }
    }

    // process remaining operators and operands
    while (!operators.empty()) {
        int operand2 = operands.top(); operands.pop();
        int operand1 = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        int result = performOperation(op, operand1, operand2);
        operands.push(result);
    }

    // return the final result
    return operands.top();
}

int main() {
    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression);
    int result = evaluateInfix(expression);
    cout << "Result = " << result << endl;
    return 0;
}
