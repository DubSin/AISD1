#ifndef SORTINGSTATION_H
#define SORTINGSTATION_H

#include "stdafx.h"
#include "Stack.h"
#include <cmath>

class SortingStation{
    private:
        bool isOperator(char c) const {
            return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
        }

        int precedence(char op) const {
            switch (op) {
            case '+': case '-': return 1;
            case '*': case '/': return 2;
            case '^': return 3;
            default: return 0;
            }
        }

        bool isRightAssociative(char op) const {
            return op == '^';
        }

        bool isFunction(const std::string& str, size_t pos) const {
            if (pos + 2 >= str.length()) return false;
            std::string substr = str.substr(pos, 3);
            return substr == "sin" || substr == "cos";
        }

        char getFunctionType(const std::string& str, size_t pos) const {
            if (pos + 2 >= str.length()) return 0;
            std::string substr = str.substr(pos, 3);
            if (substr == "sin") return 's';
            if (substr == "cos") return 'c';
            return 0;
        }

        double applyOperator(char op, double a, double b) const {
            switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/':
                if (b == 0) throw std::runtime_error("Division by zero");
                return a / b;
            case '^': return pow(a, b);
            default: throw std::runtime_error("Invalid operator");
            }
        }

    public:
        std::string infixToPostfix(const std::string& infix) {
            Stack<char> operators;
            std::string postfix;

            for (size_t i = 0; i < infix.length(); i++) {
                char c = infix[i];

                if (c == ' ') continue;

                if (isdigit(c) || c == '.') {
                    postfix += c;
                    if (i + 1 >= infix.length() || (!isdigit(infix[i + 1]) && infix[i + 1] != '.')) {
                        postfix += ' ';
                    }
                }
                else if (isFunction(infix, i)) {
                    char funcType = getFunctionType(infix, i);
                    operators.push(funcType);
                    i += 2; 
                }
                else if (c == '(') {
                    operators.push(c);
                }
                else if (c == ')') {
                    while (!operators.empty() && operators.top() != '(') {
                        postfix += operators.top();
                        postfix += ' ';
                        operators.pop();
                    }
                    if (!operators.empty() && operators.top() == '(') {
                        operators.pop();
                    }
                    else {
                        throw std::runtime_error("Mismatched parentheses");
                    }
                    if (!operators.empty() && (operators.top() == 's' || operators.top() == 'c')) {
                        postfix += operators.top();
                        postfix += ' ';
                        operators.pop();
                    }
                }
                else if (isOperator(c)) {
                    if (c == '-' && (i == 0 || infix[i - 1] == '(' || isOperator(infix[i - 1]))) {
                        operators.push('~');
                        continue;
                    }

                    while (!operators.empty() && operators.top() != '(' &&
                        (precedence(operators.top()) > precedence(c) ||
                            (precedence(operators.top()) == precedence(c) && !isRightAssociative(c)))) {
                        postfix += operators.top();
                        postfix += ' ';
                        operators.pop();
                    }
                    operators.push(c);
                }
            }

            while (!operators.empty()) {
                if (operators.top() == '(') {
                    throw std::runtime_error("Mismatched parentheses");
                }
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }

            return postfix;
        }

        double evaluatePostfix(const std::string& postfix) {
            Stack<double> values;

            for (size_t i = 0; i < postfix.length(); i++) {
                char c = postfix[i];

                if (c == ' ') continue;

                if (isdigit(c) || c == '.') {
                    std::string numStr;
                    while (i < postfix.length() && (isdigit(postfix[i]) || postfix[i] == '.')) {
                        numStr += postfix[i++];
                    }
                    i--; 

                    values.push(std::stod(numStr));
                }
                else if (isOperator(c)) {
                    if (values.size() < 2) throw std::runtime_error("Invalid expression");

                    double b = values.top(); values.pop();
                    double a = values.top(); values.pop();
                    values.push(applyOperator(c, a, b));
                }
                else if (c == '~') {
                    if (values.empty()) throw std::runtime_error("Invalid expression");
                    double a = values.top(); values.pop();
                    values.push(-a);
                }
                else if (c == 's') { // sin
                    if (values.empty()) throw std::runtime_error("Invalid expression");
                    double a = values.top(); values.pop();
                    values.push(sin(a));
                }
                else if (c == 'c') { // cos
                    if (values.empty()) throw std::runtime_error("Invalid expression");
                    double a = values.top(); values.pop();
                    values.push(cos(a));
                }
            }

            if (values.size() != 1) throw std::runtime_error("Invalid expression");
            return values.top();
        }

        double evaluateInfix(const std::string& infix) {
            std::string postfix = infixToPostfix(infix);
            std::cout << "Postfix notation: " << postfix << std::endl;
            return evaluatePostfix(postfix);
    
    }
};

#endif