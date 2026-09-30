#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Check whether character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// ---------------- PREFIX TO INFIX ----------------
string prefixToInfix(string prefix) {

    stack<string> s;

    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {

        char ch = prefix[i];

        if (isalnum(ch)) {
            s.push(string(1, ch));
        }
        else if (isOperator(ch)) {

            string operand1 = s.top();
            s.pop();

            string operand2 = s.top();
            s.pop();

            string expression = "(" + operand1 + ch + operand2 + ")";

            s.push(expression);
        }
    }

    return s.top();
}

// ---------------- INFIX TO POSTFIX ----------------
int precedence(char ch) {

    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    return 0;
}

string infixToPostfix(string infix) {

    stack<char> s;
    string postfix = "";

    for (char ch : infix) {

        if (isalnum(ch)) {
            postfix += ch;
        }

        else if (ch == '(') {
            s.push(ch);
        }

        else if (ch == ')') {

            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            s.pop();   // Remove '('
        }

        else if (isOperator(ch)) {

            while (!s.empty() &&
                   precedence(s.top()) >= precedence(ch)) {

                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// ---------------- POSTFIX EVALUATION ----------------
int postfixEvaluation(string postfix) {

    stack<int> s;

    for (char ch : postfix) {

        if (isdigit(ch)) {
            s.push(ch - '0');
        }

        else if (isOperator(ch)) {

            int operand2 = s.top();
            s.pop();

            int operand1 = s.top();
            s.pop();

            int result;

            if (ch == '+')
                result = operand1 + operand2;

            else if (ch == '-')
                result = operand1 - operand2;

            else if (ch == '*')
                result = operand1 * operand2;

            else
                result = operand1 / operand2;

            s.push(result);
        }
    }

    return s.top();
}

// ---------------- MAIN ----------------
int main() {

    string prefix;

    cout << "Enter prefix expression: ";
    cin >> prefix;

    // Prefix -> Infix
    string infix = prefixToInfix(prefix);

    cout << "Infix Expression: " << infix << endl;

    // Infix -> Postfix
    string postfix = infixToPostfix(infix);

    cout << "Postfix Expression: " << postfix << endl;

    // Postfix Evaluation
    int result = postfixEvaluation(postfix);

    cout << "Result: " << result << endl;

    return 0;
}
