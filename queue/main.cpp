#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include "queue.hpp"

using namespace std;

int main() {

    //You can check if your code works well.

    cout<<__cplusplus<<endl;

    Queue<int> q;

    cout<<boolalpha;
    cout<<q.isFull()<<endl;

    q.enqueue(1,1);
    q.enqueue(2,2);
    q.enqueue(3,3);
    q.enqueue(4,4);
    q.enqueue(5,5);
    q.enqueue(6,6);
    q.enqueue(7,7);
    q.enqueue(8,8);
    q.enqueue(1,1);
    q.enqueue(2,2);
    q.enqueue(3,3);
    q.enqueue(4,4);
    q.enqueue(5,5);
    q.enqueue(6,6);
    q.enqueue(7,7);
    q.enqueue(8,8);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    q.enqueue(5,5);
    q.enqueue(6,6);
    q.enqueue(7,7);
    q.enqueue(8,8);

    cout<<q.isFull()<<endl;
    cout<<q.top()<<endl;

    cout<<q.dequeue()<<endl;
    cout<<q.top()<<endl;

    return 0;

}