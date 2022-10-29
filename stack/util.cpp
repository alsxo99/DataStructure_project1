#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "stack.hpp"

using namespace std;

bool checkParentheses(const string& line, const vector<pair<char,char>>& pairs){
    //TODO
    Stack<char> parentheses;
    
    for (auto c : line)
    {
        // time complexity 괜찮나?
        for (auto p : pairs)
        {
            if (c == p.first)
            {
                parentheses.push(c);
            } else if(c == p.second) {
                
                if (parentheses.isEmpty() || parentheses.pop() != p.first)
                {
                    return false;
                }
                
            } else {
                // 그냥 지나가
            }
        }
        
    }
    
    return true;
}

int pref(char c) {

    if (c == '*' || c == '/')
    {
        return 2;
    }

    if (c == '+' || c == '-')
    {
        return 1;
    }

    // '(' 일 경우.
    return 0;
}

string infixToPostfix(const string& line) {

    Stack<float> numbers;
    Stack<char> operators;

    string postfix_notation;

    for (int i = 0; i < int(line.length()); i++)
    {
        char c = line[i];
        // number 일 경우 바로 stack에 넣는다.
        // -2 같은 경우도 처리할 수 있어야함.
        if (c == '(') {
            operators.push(c);
        } else if (c == ')') {

            while (operators.top() != '(')
            {
                postfix_notation.push_back(operators.top());
                operators.pop();
            }
            operators.pop();

        // 이러면 c 는 char인디 
        // 확인 필요
        } else if (isdigit(c)) {
            postfix_notation.push_back(c);
            
        } else {

            if (operators.isEmpty())
            {
                operators.push(c);
            } else if (pref(c) > pref(operators.top()))
            {
                operators.push(c);
            } else {

                while (pref(c) <= pref(operators.top()))
                {
                    postfix_notation.push_back(operators.top());
                    operators.pop();
                }
                operators.push(c);
                
            }
            
            
        }
        
    }

    while (!operators.isEmpty())
    {
        postfix_notation.push_back(operators.top());
        operators.pop();
    }
    
    cout << postfix_notation << endl;
    return postfix_notation;
}


float calculate(const string& line){
    //TODO
    Stack<float> numbers;
    //Stack<char> operators;

    string postfix_notation = infixToPostfix(line);
    
    for (auto i : postfix_notation)
    {
        if (isdigit(i))
        {
            numbers.push(stof(&i));
        } else {
            float n1 = numbers.pop();
            float n2 = numbers.pop();

            float a;

            switch (i)
            {
            case '+':
                a = n2 + n1;
                break;
            
            case '-':
                a = n2 - n1;
                break;

            case '*':
                a = n2 * n1;
                break;

            case '/':
                a = n2 / n1;
                break;

            default:
                break;
            }

            numbers.push(a);
        }
    }
    
    float answer = numbers.top();
    numbers.pop();

    return answer;
}