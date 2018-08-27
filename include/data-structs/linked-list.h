#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <cstddef>
#include <unordered_set>

class EmptyStackException{};

template <class T>
class LinkedList final{
    struct Node{
        T data;
        Node *next = nullptr;
    };

    Node *head;
    size_t length;

public:
    // Constructor & Destructor
    explicit LinkedList();
    ~LinkedList();

    // Modifiers
    void appendToHead(const T &data); // O(n)
    void appendToTail(const T &data); // O(n)
    void deleteNode(const T &data); // O(n)
    void deleteIndex(const int idx); // O(n)
    void removeDups(); // O(n)

    // Utility & Print
    T get(const int idx) const; // O(1)
    size_t size() const; // O(1)
    bool isEmpty() const; // O(1)
    void print() const; // O(n)
};

// Constructor
template <class T>
LinkedList<T>::LinkedList(): head{nullptr}, length{0}{}

// Destructor
template <class T>
LinkedList<T>::~LinkedList(){
    Node *temp;

    while(head){
        temp = head->next;
        delete head;
        head = temp;
    }
}

// Adds a new Node to the beginning
template <class T>
void LinkedList<T>::appendToHead(const T &data){
    try{
        Node *newNode = new Node{data, head};
        head = newNode;
        ++length;
    }catch(const std::bad_alloc &e){
        std::cerr << "Did not append element: " << e.what() << std::endl;
        throw;
    }
}

// Appends a new Node
template <class T>
void LinkedList<T>::appendToTail(const T &data){
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
void LinkedList<T>::deleteNode(const T &data){
    Node *temp;
    Node *curr = head;

    while(curr->next){

    }
}

// Deletes a node at index idx
template <class T>
void LinkedList<T>::deleteIndex(const int idx){
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

// Removes duplicates
template <class T>
void LinkedList<T>::removeDups(){
    std::unordered_set<T> dict;
    Node *prev;
    Node *curr = head;

    while(curr){
        const T data = curr->data;
        if(dict.find(data) == dict.end()){
            dict.emplace(data);
            prev = curr;
            curr = curr->next;
        }else{
            prev->next = curr->next;
            delete curr;
            --length;
            curr = prev->next;
        }
    }
}

// Returns the # of Nodes
template <class T>
size_t LinkedList<T>::size() const{
    return length;
}

// Returns true if there are no Nodes in the linked list and false otherwise
template <class T>
bool LinkedList<T>::isEmpty() const{
    return length == 0;
}

// Prints the elements of the linked list in the form x1 -> x2 -> ... -> xn
template <class T>
void LinkedList<T>::print() const{
    Node *curr = head;

    if(!curr) std::cout << "empty";

    while(curr){
        std::cout << curr->data;
        if(curr->next) std::cout << " -> ";
        curr = curr->next;
    }
}

/*
    // LinkedList Tests
    LinkedList<int> theList;

    cout << "Is the list empty? " << (theList.isEmpty() ? "yes" : "no") << endl;
    cout << "List has " << theList.size() << " nodes";

    theList.print();
    cout << endl;

    theList.appendToHead(3);
    theList.print();
    cout << endl;

    theList.appendToHead(2);
    theList.print();
    cout << endl;

    theList.appendToTail(4);
    theList.print();
    cout << endl;

    theList.appendToTail(5);
    theList.print();
    cout << endl;

    theList.appendToHead(1);
    theList.print();
    cout << endl;

    theList.appendToHead(1);
    theList.print();
    cout << endl;

    theList.appendToHead(4);
    theList.print();
    cout << endl;

    cout << "Is the list empty? " << (theList.isEmpty() ? "yes" : "no") << endl;
    cout << "List has " << theList.size() << " nodes" << endl;

    cout << "Remove duplicates" << endl;
    theList.removeDups();
    theList.print();
    cout << endl;

    cout << "Deleting head" << endl;
    theList.deleteIndex(0);
    theList.print();
    cout << endl;

    cout << "Length is now " << theList.size() << endl;

    cout << "Deleting tail" << endl;
    theList.deleteIndex(theList.size() - 1);
    theList.print();
    cout << endl;

    cout << "Deleting index: 1" << endl;
    theList.deleteIndex(1);
    theList.print();
    cout << endl;
*/

#endif