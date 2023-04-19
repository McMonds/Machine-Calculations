#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int precedence(char op) 
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

string infixToPostfix(string expression) 
{
    stack<char> s;
    string postfix = " ";
    for (int i = 0; i < expression.length(); i++) 
    {
        if (isalnum(expression[i]))
        {
             postfix += expression[i];
        }
        else if (expression[i] == '(')
            {
                s.push('(');
            }
        else if (expression[i] == ')') 
        {
            while (!s.empty() && s.top() != '(') 
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop();
        } 
        else 
        {
            while (!s.empty() && precedence(expression[i]) <= precedence(s.top())) 
            {
                postfix += s.top();
                s.pop();
            }
            s.push(expression[i]);
        }
    }
    while (!s.empty()) 
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

string infixToPrefix(string exp) 
{
    reverse(exp.begin(), exp.end());
    for (int i = 0; i < exp.length(); i++) 
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
    string prefix = infixToPostfix(exp);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string postfixToInfix(string exp) 
{
    stack<string> s;
    for (int i = 0; i < exp.length(); i++) 
    {
        if (isalnum(exp[i])) 
        {
            string operand(1, exp[i]);
            s.push(operand);
        } 
        else 
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string result = "(" + op2 + exp[i] + op1 + ")";
            s.push(result);
        }
    }
    return s.top();
}

string prefixToInfix(string exp) 
{
    stack<string> s;
    for (int i = exp.length() - 1; i >= 0; i--) 
    {
        if (isalnum(exp[i])) 
        {
            string operand(1, exp[i]);
            s.push(operand);
        } 
        else 
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string result = "" + op1 + exp[i] + op2 + "";
            s.push(result);
        }
    }
    return s.top();
}

string postfixToPrefix(string exp) 
{
    stack<string> s;
    for (int i = 0; i < exp.length(); i++) 
    {
        if (isalnum(exp[i])) 
        {
            string operand(1, exp[i]);
            s.push(operand);
        } 
        else 
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string result = exp[i] + op2 + op1;
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    int choice;
    string expression;
    cout << "Choose conversion type: " << endl;
    cout << "1. Infix to Postfix" << endl;
    cout << "2. Infix to Prefix" << endl;
    cout << "3. Postfix to Infix" << endl;
    cout << "4. Prefix to Infix" << endl;
    cout << "5. Postfix to prefix" << endl;
    cin >> choice;
    cin.ignore();
    cout << "Enter expression: ";
    getline(cin, expression);
    switch (choice) 
    {
        case 1:
            cout << "Infix to Postfix expression : " << infixToPostfix(expression) << endl;
            break;
        case 2:
            cout << "Infix to Prefix expression : " << infixToPrefix(expression) << endl;
            break;
        case 3:
            cout << "Postfix to Infix expression : " << postfixToInfix(expression) << endl;
            break;
        case 4:
            cout << "Prefix to Infix expression : " << prefixToInfix(expression) << endl;
            break;
        case 5:
            cout << "Postfix to Prefix expression : " << postfixToPrefix(expression) << endl;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    return 0;
}