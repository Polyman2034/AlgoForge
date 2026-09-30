/*
Practical No. 06 - STACK

Given as input a prefix expression.
Implement a program for following conversions:

a) Prefix to Infix
b) Infix to Postfix
c) Postfix Evaluation
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;


// STACK CLASS
class Stack
{
public:
    stack<string> s;

    void prefixToInfix(string prefix);
    void infixToPostfix(string infix);
    void postfixEvaluation(string postfix);

    bool isOperator(char ch);
    int precedence(char ch);
};


// CHECK OPERATOR
bool Stack::isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}


// OPERATOR PRECEDENCE
int Stack::precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    return 0;
}


// PREFIX TO INFIX
void Stack::prefixToInfix(string prefix)
{
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (isalnum(ch))
        {
            s.push(string(1, ch));
        }
        else if (isOperator(ch))
        {
            string operand1 = s.top();
            s.pop();

            string operand2 = s.top();
            s.pop();

            string expression = "(" + operand1 + ch + operand2 + ")";

            s.push(expression);
        }
    }

    string infix = s.top();

    cout << "Infix Expression: " << infix << endl;

    infixToPostfix(infix);
}


// INFIX TO POSTFIX
void Stack::infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix += ch;
        }

        else if (ch == '(')
        {
            s.push(ch);
        }

        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            s.pop();
        }

        else if (isOperator(ch))
        {
            while (!s.empty() &&
                   precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;

    postfixEvaluation(postfix);
}


// POSTFIX EVALUATION
void Stack::postfixEvaluation(string postfix)
{
    stack<int> s;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            s.push(ch - '0');
        }

        else if (isOperator(ch))
        {
            int operand2 = s.top();
            s.pop();

            int operand1 = s.top();
            s.pop();

            int result;

            switch (ch)
            {
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
            }

            s.push(result);
        }
    }

    cout << "Result: " << s.top() << endl;
}


// MAIN FUNCTION
int main()
{
    string prefix;

    Stack expression;

    cout << "Enter prefix expression: ";
    cin >> prefix;

    cout << "\n----- EXPRESSION CONVERSION -----\n";

    expression.prefixToInfix(prefix);

    return 0;
}
