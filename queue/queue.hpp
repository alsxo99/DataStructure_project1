#include <iostream>

template <typename T>
struct Item{
    T value;
    int priority;

};

template <typename T>
class Queue{
    private:
        int front;
        int rear;
        bool empty;
        int size;
        Item<T> *array;

    public:
        Queue<T>(int _size = 16)
        {
            front = 0;
            rear = _size - 1;
            empty = true;
            size = _size;
            array = new Item<T>[_size];
        }
        ~Queue(){
            delete[] array;
        }

        void enqueue(const T& value, int priority);
        int top();
        T dequeue();        
        bool isFull();
};

template <typename T>
void Queue<T>::enqueue(const T& value, int priority){
    //TODO
    if (empty){
        rear = -1;
        empty = false;
    } 
    
    if (isFull()) 
    {
        Item<T> *array2 = new Item<T>[size * 2];

        // copy for loop 은 끝까지 다 돈다.
        for (int i = 0; i < size; i++)
        {
            if (front + i >= size) front -= size;
            array2[i].value = array[front + i].value;
            array2[i].priority = array[front + i].priority;

        }
        
        array2[size].value = value;
        array2[size].priority = priority;

        delete[] array;

        // copy 문제 발생하려나 ??
        front = 0;
        rear = size;
        size = size * 2;
        array = array2;
        
    } else {
        if (rear + 1 == size)
        {
            // rear = -1 과 같은 표현.
            rear -= size;
        }
        
        array[rear + 1].value = value;
        array[rear + 1].priority = priority;
        rear++;
    }
    
    return;
}

template <typename T>
int Queue<T>::top(){
    //TODO
    //returning the array index of the highest priority item
    
    // 예외처리 안해도 됨.
    // if (empty) return -1;

    int index = 0;
    int highest_priority = 0;
    int copy_front = front;

    for (int i = 0; i < size; i++)
    {
        // front 부터 검색, 끝에서 다시 앞으로
        if (copy_front + i >= size) copy_front -= size;

        if(array[copy_front + i].priority > highest_priority)
        {
            highest_priority = array[copy_front + i].priority;
            index = copy_front + i;
        }

        // rear 에 도달하면 break.
        // 제대로 작동하는지 확인해아함
        if (copy_front + i == rear) break;
    }
    
    return index;
}

template <typename T>
T Queue<T>::dequeue(){
    //TODO
    // 1개 있을 때 dequeue 하면 empty 인거 해야함.
    
    // exception 처리 안해도됨.
    // if (empty) return -1;

    int index = top();
    int val;

    // return 할 value
    val = array[index].value;
    
    if (index == front)
    {
        front++;
    } else if (index == rear)
    {
        rear--;
    } else {
        // index 부터 한칸씩 왼쪽으로 옮기면서 copy
        while (index != front)
        {
            // 왼쪽으로 옮기다가 0 index 에 복사를 해야하는 경우
            if (index == 0)
            {
                array[index].value = array[size - 1].value;
                array[index].priority = array[size - 1].priority;
                index = size - 1;
            } else { // 나머지 일반적인 경우들
                array[index].value = array[index - 1].value;
                array[index].priority = array[index - 1].priority;
                index--;
            }
            
        }
        front++;  
    }

    // 1개일때 dequeue 하면 empty = true
    if (front == rear + 1) empty = true;
    
    return val;
}

template <typename T>
bool Queue<T>::isFull(){
    //TODO
    return ((rear != -1 && rear + 1 == front) || (!empty && (front == 0 && rear == size - 1)));
}