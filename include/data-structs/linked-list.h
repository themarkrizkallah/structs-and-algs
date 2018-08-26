#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <cstddef>

/* Singly Linked List */
template <class T>
class SinglyLinkedList final{
    struct Node{
        T data;
        Node *next = nullptr;
    };

    size_t length;
    Node *head;

public:
    // Constructor & Destructor
    explicit SinglyLinkedList();
    ~SinglyLinkedList();

    // Modifiers
    void appendToHead(const T &data); // O(n)
    void appendToTail(const T &data); // O(n)
    void deleteNode(const T &data); // O(n)
    void deleteIndex(const int idx); // O(n)

    // Utility & Print
    T get(const int idx) const; // O(1)
    size_t size() const; // O(1)
    bool isEmpty() const; // O(1)
    void print() const; // O(n)
};

/* SinglyLinkedList - Implementation */

// Constructor
template <class T>
SinglyLinkedList<T>::SinglyLinkedList(): length{0}, head{nullptr}{}

// Destructor
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList(){
    Node *temp;
    Node *curr = head;

    while(curr){
        temp = curr->next;
        delete curr;
        curr = temp;
    }
}

// Adds a new Node to the beginning of the singly linked list
template <class T>
void SinglyLinkedList<T>::appendToHead(const T &data){
    try{
        Node *newNode = new Node{data, head};
        head = newNode;
        ++length;
    }catch(const std::bad_alloc &e){
        std::cerr << "Did not append element: " << e.what() << std::endl;
        throw;
    }
}

// Appends a new Node to the singly linked list
template <class T>
void SinglyLinkedList<T>::appendToTail(const T &data){
    try{
        Node *newNode = new Node{data};
        Node *end = head;

        if(end){
            while(end->next) end = end->next;
            end->next = newNode;
        }else end = newNode;

        ++length;
    }catch(const std::bad_alloc &e){
        std::cerr << "Did not append element: " << e.what() << std::endl;
        throw;
    }
}

// Deletes a node with specific value data
template<class T>
void SinglyLinkedList<T>::deleteNode(const T &data){
    Node *temp;
    Node *curr = head;

    while(curr->next){

    }
}

// Deletes a node at index idx
template <class T>
void SinglyLinkedList<T>::deleteIndex(const int idx){
    if(idx < length && idx >= 0){
        Node *prev;
        Node *curr = head;
        
        for(int i = 0; i < idx; ++i){
            prev = curr;
            curr = curr->next; 
        }

        if(idx == 0) head = curr->next;
        else if(idx == length - 1) prev->next = nullptr;
        else prev->next = curr->next; 

        delete curr;
        --length;
    }else std::cerr << "Index out of range." << std::endl;
}

// Returns the # of Nodes in the singly linked list
template <class T>
size_t SinglyLinkedList<T>::size() const{
    return length;
}

// Returns true if there are no Nodes in the singly linked list and false otherwise
template <class T>
bool SinglyLinkedList<T>::isEmpty() const{
    return length == 0;
}

// Prints the elements of the singly linked list in the form x1 -> x2 -> ... -> xn
template <class T>
void SinglyLinkedList<T>::print() const{
    Node *curr = head;

    if(!curr) std::cout << "List is empty";

    while(curr){
        std::cout << curr->data;
        if(curr->next) std::cout << " -> ";
        curr = curr->next;
    }
} 
#endif