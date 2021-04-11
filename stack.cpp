#include "stack.hpp"

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
