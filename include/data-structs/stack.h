#ifndef _STACK_H
#define _STACK_H
#include <cstddef>

template <class T>
class Stack final{
    struct Node{
        T data;
        Node *next = nullptr;      
    };

    Node *top;
    size_t length;

public:
    // Constructor & Destructor
    explicit Stack();
    ~Stack();

    // Modifiers
    T pop(); // O(1)
    void push(const T &elem); // O(1)

    // Utility & Print
    T peek() const; // O(1)
    size_t size() const; // O(1)
    bool isEmpty() const; // O(1)
    void print() const; // O(n)

};

// Constructor
template <class T>
Stack<T>::Stack(): top{nullptr}, length{0}{}

// Destructor
template <class T>
Stack<T>::~Stack(){
    Node *temp;

    while(top){
        temp = top->next;
        delete top;
        top = temp;
    }
}

// Removes and returns the element from the top
template <class T>
T Stack<T>::pop(){
    if(top == nullptr) throw new EmptyStackException();

    T data = top->data;
    Node *temp = top;
    
    top = top->next;
    delete temp;
    --length;

    return data;
}

// Adds an element to the top
template <class T>
void Stack<T>::push(const T &elem){
    Node *newNode = new Node{elem, top};
    top = newNode;
    ++length;
}

// Returns the data at the top
template <class T>
T Stack<T>::peek() const{
    if(top == nullptr) throw new EmptyStackException();
    return top->data;
}

// Returns the size of the stack
template <class T>
size_t Stack<T>::size() const{
    return length;
}

// Returns true if the stack is empty and false otherwise
template <class T>
bool Stack<T>::isEmpty() const{
    return top == nullptr;
}

// Prints the elements of the stack in the form x1 x2 ... xn
template <class T>
void Stack<T>::print() const{
    Node *curr = top;

    if(!curr) std::cout << "empty";

    while(curr){
        std::cout << curr->data;
        if(curr->next) std::cout << ' ';
        curr = curr->next;
    }
}

#endif