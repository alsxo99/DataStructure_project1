#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "stack.hpp"

using namespace std;

struct mem
{
    char value;
    bool isOpen = true;
};


bool checkParentheses(const string& line, const vector<pair<char,char>>& pairs){
    //TODO
    // 빈 string 이면 true로 return.
    if (line.length() == 0)
    {
        return true;
    }

    Stack<char> parentheses;
    int count = 0;
    // 여는 괄호와 닫는 괄호가 동일한 녀석들의 개수를 세준다.
    for (auto p : pairs)
    {
        if (p.first == p.second)
        {
            count++;
        }   
    }
    
    // 종류와 isopen을 저장할 mem array를 만든다.
    mem* arr = new mem[count];

    // 다시 한번 for loop을 돌면서 녀석들의 값을 넣어준다.
    int i = 0;
    for (auto p : pairs)
    {   
        if (p.first == p.second)
        {
            arr[i].value = p.first;
            i++;
        }
    }
    
    for (auto c : line)
    {
        // time complexity 괜찮나?
        for (auto p : pairs)
        {   
            if (c == p.first && c != p.second) // 일반적인 여는 괄호
            {   
                parentheses.push(c);
            } else if(c != p.first && c == p.second) { // 일반적인 닫는 괄호
                
                if (parentheses.isEmpty() || parentheses.top() != p.first)
                {
                    return false;
                }
                parentheses.pop();
            } else if(c == p.first && c == p.second) { // 여는 괄호와 닫는 괄호가 같은 경우
                
                bool isOpen;
                int index;

                for (int j = 0; j < count; j++)
                {
                    if (arr[j].value == c)
                    {
                        isOpen = arr[j].isOpen;
                        index = j;
                    }
                    
                }

                if (isOpen) // isOpen 이라는 변수를 이용해서 여는 경우인지, 닫는 경우인지 확인 해준다.
                {
                    parentheses.push(c);
                    arr[index].isOpen = false;
                } else {
                    if (parentheses.isEmpty() || parentheses.top() != c)
                    {
                        return false;
                    }
                    parentheses.pop();
                    arr[index].isOpen = true;
                }
                
            }
        }
        
    }
    
    if (!parentheses.isEmpty())
    {
        return false;
    }
    
    delete[] arr;

    return true;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
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

    //Stack<float> numbers;
    Stack<char> operators;
    
    string postfix_notation;
    size_t sz = 0;
    size_t count = 0;

    for (int i = 0; i < int(line.length()); i++)
    {
        char c = line[i];
        // number 일 경우 바로 stack에 넣는다.
        // -2 같은 경우도 처리할 수 있어야함.
        if (c == '(') {
            operators.push(c);
            sz++;
        } else if (c == ')') {

            while (operators.top() != '(')
            {
                postfix_notation.push_back(operators.top());
                postfix_notation.append(" ");
                operators.pop();
            }
            operators.pop();
            sz++;
        } else if (isOperator(c)) { // 연산자들

            // unary operator ( 부호 )
            if ((c == '+' || c == '-') && (line[i - 1] == '('))
            {
                count += sz;
                float num = stof(line.substr(i), &sz);
                i = count + sz - 1;

                postfix_notation.append(to_string(num));
                postfix_notation.append(" ");
                sz--;
            } else if (operators.isEmpty())
            {
                operators.push(c);
            } else if (pref(c) > pref(operators.top()))
            {
                operators.push(c);
            } else {

                while (pref(c) <= pref(operators.top()))
                {
                    postfix_notation.push_back(operators.top());
                    postfix_notation.append(" ");
                    operators.pop();
                }
                operators.push(c);
            }
            sz++;
        } else { // 숫자
            // 현재 숫자가 있는 index
            count += sz;
            float num = stof(line.substr(count), &sz);
            // 숫자가 끝나는 index
            i = count + sz - 1;
            
            postfix_notation.append(to_string(num));
            postfix_notation.append(" ");
        }
        
    }

    while (!operators.isEmpty())
    {
        postfix_notation.push_back(operators.top());
        postfix_notation.append(" ");
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
    size_t sz = 0;
    size_t count = 0;
    
    for (int i = 0; i < int(postfix_notation.length()); i++)
    {
        if (postfix_notation[i] == ' ')
        {
            sz++;
        } else if (isOperator(postfix_notation[i])) {

            // 부호를 나타내는 + 나 - 인 경우,
            if ((postfix_notation[i] == '+' || postfix_notation[i] == '-') && (isdigit(postfix_notation[i+1]) || postfix_notation[i+1] == '.'))
            {
                count += sz;
                float num = stof(postfix_notation.substr(count), &sz);
                i = count + sz - 1;

                numbers.push(num);
            } else {
                float n1 = numbers.pop();
                float n2 = numbers.pop();

                float a;

                switch (postfix_notation[i])
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
                sz++;
                }
            
        } else {
            count += sz;
            float num = stof(postfix_notation.substr(count), &sz);
            i = count + sz - 1;
            
            numbers.push(num);
        }
    }
    
    float answer = numbers.top();
    numbers.pop();

    return answer;
}