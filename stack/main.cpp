#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include "stack.hpp"

using namespace std;

int main() {

    //You can check if your code works well.

    cout<<__cplusplus<<endl;

    Stack<int> s;

    cout<<boolalpha;
    cout<<s.isEmpty()<<endl;
    cout<<s.isFull()<<endl;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    s.push(17);
    

    cout<<s.isEmpty()<<endl;
    cout<<s.isFull()<<endl;

    cout<<s.pop()<<endl;

    pair<char,char> p1 = make_pair('(',')');
    pair<char,char> p2 = make_pair('{','}');
    pair<char,char> p3 = make_pair('#','#');

    vector<pair<char,char>> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    string a = "(3))";
    string b = "({>})";
    string c = "(({[3}))";
    string d = "#3##";
    string e = "(a)yoa";

    cout<<checkParentheses(a, v)<<endl;
    cout<<checkParentheses(b, v)<<endl;
    cout<<checkParentheses(c, v)<<endl;
    cout<<checkParentheses(d, v)<<endl;
    cout<<checkParentheses(e, v)<<endl;

    cout << calculate("(1.25+2.75)/3.2") << endl;
    cout << calculate("((1+3)/2)/2") << endl;
    cout << calculate("1+2") << endl;
    cout << calculate("1+(-1)") << endl;
    cout << calculate("3*(-4)/2") << endl;
    cout << calculate("(1+(-1)+1+(-1)*5+(-2)+3*5+1+(-1)+1+(-1)+1+(-1)+1+(-1)+1+(-1))") << endl;
    cout << calculate("(25.5+23.5)/4") << endl;

}