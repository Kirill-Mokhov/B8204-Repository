#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <set>
#include <string>
#include <stack>
#include <utility>

using namespace std;

set <char> Numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
set <char> Operations = {'*', '+', '-', '/', '(', ')'};

class Postfix
{
protected:
    stack<int> expressionsStack;
    string expression;

public:
    Postfix(string in) : expression(in){}
    ~Postfix(){}

    int Perform()
    {
        int rVal, lVal, result;
        string q;
        bool isNum(false);

        for (char i : expression)
        {
            if(Numbers.find(i) != Numbers.end())
                {
                    isNum = true;
                    q += i;
                }
            else
                {
                if(isNum){
                    isNum = false;
                    expressionsStack.push(atoi(q.data()));
                    q = "";
                }

                if(Operations.find(i) != Operations.end()) {
                    rVal = expressionsStack.top();
                    expressionsStack.pop();
                    lVal = expressionsStack.top();
                    expressionsStack.pop();

                    switch(i) {
                        case '*': expressionsStack.push(lVal * rVal); break;
                        case '+': expressionsStack.push(lVal + rVal); break;
                        case '-': expressionsStack.push(lVal - rVal); break;
                        case '/': expressionsStack.push(lVal / rVal); break;
                        default : break;
                    }
                }
            }
        }
        if(isNum)
        {
            expressionsStack.push(atoi(q.data()));
        }

        result = expressionsStack.top();
        expressionsStack.pop();

        if(!expressionsStack.empty())
        {
            cout << "Error : Stack isn't empty." << endl;
            //throw logic_error("Error : Stack isn't empty.");
        }

        return result;
    }
};

class Converter
{
protected:
    stack<pair<char, int>> expressionsStack;

public:
    string Convert(string inExpression)
    {
        string outExpression;
        bool inNum(false);
        string q;
        bool Bracket(false);

        for (char i : inExpression)
        {
            if (Numbers.find(i) != Numbers.end())
            {
                inNum = true;
                q += i;
            }
            else
            {
                if (inNum)
                {
                    outExpression += (q + ' ');
                    inNum = false;
                    q = "";
                }
                if (Operations.find(i) != Operations.end())
                {
                    pair<char, int> token;
                    switch (i)
                    {
                        case '(' : token = pair<char, int>(i, 0); break;
                        case '+' : case '-' : token = pair<char, int>(i, 1); break;
                        case '*' : case '/' : token = pair<char, int>(i, 2); break;
                        case ')' : token = pair<char, int>(i, 3); break;
                        default: break;
                    }
                    if (i == '(')
                    {
                        Bracket = true;
                        expressionsStack.push(token);
                    }
                    else if (i == ')')
                    {
                        if (!Bracket)
                        {
                            cout << "Error : Check your brackets." << endl;
                            //throw logic_error("Error : Check your brackets.");
                        }

                        Bracket = false;

                        while (expressionsStack.top().first != '(')
                        {
                            outExpression += expressionsStack.top().first;
                            expressionsStack.pop();
                        }

                        if (expressionsStack.empty())
                        {
                            cout << "Emptiness" << endl;
                            //throw logic_error("Emptiness");
                        }

                        expressionsStack.pop();
                    }

                    else
                    {
                        while (!expressionsStack.empty() && expressionsStack.top().second >= token.second)
                        {
                            outExpression += expressionsStack.top().first;
                            expressionsStack.pop();
                        }

                        expressionsStack.push(token);

                    }
                }
            }
        }
        if (inNum)
        {
            outExpression += (q + ' ');
        }
        if (Bracket)
        {
            cout << "Please, CHECK YOUR BRACKETS" << endl;
            //throw logic_error("Please, CHECK YOUR BRACKETS");
        }
        while (!expressionsStack.empty())
        {
            outExpression += expressionsStack.top().first;
            expressionsStack.pop();
        }
        return outExpression;
    }
};



#endif // HEADER_H_INCLUDED
