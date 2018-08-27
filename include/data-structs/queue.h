#ifndef _QUEUE_H
#define _QUEUE_H
#include <cstddef>

class NoSuchElementException{};

template <class T>
class Queue final{
    struct Node{
        T data;
        Node *next = nullptr;      
    };

    Node *first;
    Node *last;
    size_t length;

public:
    // Constructor & Destructor
    explicit Queue();
    ~Queue();

    // Modifiers
    void add(const T &elem); // O(1)
    T remove(); // O(1)

    // Utility & Print
    T peek() const; // O(1)
    size_t size() const; // O(1)
    bool isEmpty() const; // O(1)
    void print() const; // O(n)
};

// Constructor
template <class T>
Queue<T>::Queue(): first{nullptr}, last{nullptr}, length{0}{}

// Destructor
template <class T>
Queue<T>::~Queue(){
    Node *temp;

    while(first){
        temp = first->next;
        delete first;
        first = temp;
    }
}

// Appends a new Node
template <class T>
void Queue<T>::add(const T &elem){
    Node *newNode = new Node{elem};

    if(last != nullptr) last->next = newNode;

    last = newNode;

    if(first == nullptr) first = last;

    ++length;
}

// Removes first element
template <class T>
T Queue<T>::remove(){
    if(first == nullptr) throw NoSuchElementException{};

    T data = first->data;
    Node *temp = first;
    first = first->next;
    delete temp;
    --length;

    if(first == nullptr) last = nullptr;

    return data;
}

// Return first element
template <class T>
T Queue<T>::peek() const{
    if(first == nullptr) throw NoSuchElementException{};

    return first->data;
}

// Returns the size of the queue
template <class T>
size_t Queue<T>::size() const{
    return length;
}

// Returns true if the stack is empty and false otherwise
template <class T>
bool Queue<T>::isEmpty() const{
    return first == nullptr;
}

// Prints the elements of the stack in the form x1 <- x2 <- ... <- xn
template <class T>
void Queue<T>::print() const{
    Node *curr = first;

    if(!curr) std::cout << "empty";

    while(curr){
        std::cout << curr->data;
        if(curr->next) std::cout << " <- ";
        curr = curr->next;
    }
}

/*
    // Queue tests
    Queue<int> q;

    cout << "The Queue is ";
    q.print();
    cout << endl;

    q.add(1);
    cout << "The Queue: ";
    q.print();
    cout << endl;

    q.add(2);
    q.add(3);
    cout << "The Queue: ";
    q.print();
    cout << endl;

    q.remove();
    cout << "The Queue: ";
    q.print();
    cout << endl;

    q.remove();
    q.remove();

    cout << "Is the Queue empty? " << (q.isEmpty() ? "yes" : "no") << endl;
*/

#endif