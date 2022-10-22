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

float calculate(const string& line){
    //TODO
    Stack<float> numbers;
    Stack<char> operators;
    return 0.f;
}