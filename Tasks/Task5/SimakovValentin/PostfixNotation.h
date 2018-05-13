#ifndef POSTFIXNOTATION_H
#define POSTFIXNOTATION_H

#include <stack>
#include <string>
#include <set>
#include <map>

using std::stack;
using std::pair;
using std::string;


std::set<char> digits = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
std::set<char> operations = {'+', '-', '*', '(', ')'};


const int zero_code = 48;

class PostfixNotationExpression{
protected:
    stack<int> expressionStack;
    string expression;

public:
    PostfixNotationExpression(string str) : expression(str) {}
    ~PostfixNotationExpression() {}

    int value() {
        int leftOperand(0), rightOperand(0);
        for (char i : expression) {
            if(digits.find(i) != digits.end())
                expressionStack.push(i - zero_code);

            else if(operations.find(i) != operations.end()) {
                rightOperand = expressionStack.top();
                expressionStack.pop();
                leftOperand = expressionStack.top();
                expressionStack.pop();

                switch(i) {
                    case '+':
                        expressionStack.push(leftOperand+rightOperand);
                        break;
                    case '-':
                        expressionStack.push(leftOperand-rightOperand);
                        break;
                    case '*':
                        expressionStack.push(leftOperand*rightOperand);
                        break;
                    default:break;
                }
            }
        }
        int result = expressionStack.top();
        expressionStack.pop();
        if(!expressionStack.empty()) throw std::logic_error("Wrong expression");
        return result;
    }
};

class PostfixNotationConveter {
protected:
    stack<pair<char, int>> expressionStack;

public:
    string convert(string infixNotationExpression){
        string postfixNotationExpression;
        bool openBracket = false;

        for (char i : infixNotationExpression) {
            if(digits.find(i) != digits.end())
                postfixNotationExpression += i;

            else if(operations.find(i) != operations.end()) {
                pair<char, int> token;
                switch(i) {
                    case '(': token = pair<char,int>(i, 0); break;
                    case '+': case '-': token = pair<char,int>(i, 1); break;
                    case '*': token = pair<char,int>(i, 2); break;
                    case ')': token = pair<char,int>(i, 3); break;
                    default:break;
                }
                if(i == '('){
                    openBracket = true;
                    expressionStack.push(token);
                }
                else if(i == ')'){
                    if(!openBracket) throw std::logic_error("Wrong expression");
                    openBracket = false;
                    while (expressionStack.top().first != '(') {
                        postfixNotationExpression += expressionStack.top().first;
                        expressionStack.pop();
                    }
                    if(expressionStack.empty()) throw std::logic_error("Wrong expression");
                    expressionStack.pop();
                }
                else {
                    while (!expressionStack.empty() && expressionStack.top().second >= token.second) {
                        postfixNotationExpression += expressionStack.top().first;
                        expressionStack.pop();
                    }
                    expressionStack.push(token);
                }
            }
        }
        if(openBracket) throw std::logic_error("Wrong expression");
        while(!expressionStack.empty()){
            postfixNotationExpression += expressionStack.top().first;
            expressionStack.pop();
        }
        return postfixNotationExpression;
    }
};

#endif
