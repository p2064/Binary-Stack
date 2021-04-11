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

#endif /* stack_hpp */

