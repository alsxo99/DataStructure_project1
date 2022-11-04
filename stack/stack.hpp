#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class Stack{
    private: 
        int current;
        int size;
        T * array;

    public:
        Stack<T> (int _size = 16)
        {   
            current = -1;
            size = _size;
            array = new T[_size];
        }
        ~Stack()
        {
            delete[] array;
        }    

        bool isEmpty() const;
        bool isFull() const;
        T top() const;
        T pop();
        void push(const T& item);
};

template <typename T>
bool Stack<T>::isEmpty() const{
    //TODO
    return (current == -1);
}

template <typename T>
bool Stack<T>::isFull() const{
    //TODO
    return (current == size - 1);
}

template <typename T>
T Stack<T>::top() const{
    //TODO
    // 비어있을 때 고려해야 하나?
    // exception 안해도 됨.
    return array[current];
}

template <typename T>
T Stack<T>::pop(){
    //TODO
    T value = array[current];
    current--;
    return value;
}

template <typename T>
void Stack<T>::push(const T& item){
    //TODO
    if (isFull())
    {
        // x2 array
        T * array2 = new T[size * 2];

        for (int i = 0; i < size; i++)
        {
            array2[i] = array[i];
        }

        T * old = array;
        delete[] old;

        array2[size] = item;
        
        current = size;
        size = size * 2;
        array = array2;
        
        return;
    } else {
        current++;
        array[current] = item;
    }
    
    return;
}

bool checkParentheses(const string& line, const vector<pair<char,char>>& pairs);
float calculate(const string& line);
string infixToPostfix(const string& line);