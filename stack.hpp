#ifndef stack_hpp
#define stack_hpp
#include <iostream>

using namespace std;

template <typename T>
class Stack{

private:
    struct Node {
        T value;
        Node *prevElement;
        Node(T data) {
            this->value = data;
            prevElement = nullptr;
        }
    };
    Node *topPtr;
    uint32_t size;

public:
    bool isEmpty();
    void push(T data);
    T pop();
    T top();
    Stack() : topPtr(nullptr), size(0){}
   ~Stack(){
        while (topPtr) {
            Node *node = topPtr;
            topPtr = topPtr->prevElement;
            delete node;
        }
    }

};
template <typename T>
bool Stack<T>::isEmpty(){
    return this->topPtr == nullptr;

}

template <typename T>
void Stack<T>::push(T data){
    Node *newNode = new Node(data);
    newNode->prevElement = topPtr;
    this->topPtr = newNode;
    size++;

}

template <typename T>
T Stack<T>::top(){
    if (isEmpty()) throw -1;
    else return topPtr->value;
}

template <typename T>
T Stack<T>::pop(){
    if (isEmpty()) throw -1;

    else {
        Node *tmpNode = topPtr->prevElement;
        T tmpValue = topPtr->value;
        delete topPtr;
        size--;
        topPtr = tmpNode;
        return tmpValue;
    }
}
#endif /* stack_hpp */

