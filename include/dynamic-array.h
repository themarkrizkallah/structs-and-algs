#ifndef _DYNAMIC_A_H_
#define _DYNAMIC_A_H_

// Factor used to increase capacity for DynamicArrays
const size_t DA_FACTOR = 2; 

template <class T> 
class DynamicArray final{
    T *da;
    size_t daSize;
    size_t daCapacity;

    size_t resize(); // O(n)

public:
    // Constructor & Destructor
    explicit DynamicArray();
    ~DynamicArray();

    // Modifiers
    void push(const T &elem); // O(1), reallocation may occur
    T pop(); // O(1)
    T get(const int idx); // O(1)

    // Capacity & Print
    size_t size() const; // O(1)
    size_t capacity() const; // O(1)
    bool isEmpty() const; // O(1)
    void print() const; // O(1)
};

/* Implementation */

// Resize the DynamicArray
template <class T> 
size_t DynamicArray<T>::resize(){
    size_t newCapacity = daCapacity * DA_FACTOR;
    T *temp;

    try{
        temp = new T[newCapacity];
    }catch(const std::bad_alloc &e){
        throw;
    }
   
    for(int i = 0; i < daSize; ++i) temp[i] = da[i]; // Copy data to the bigger array

    delete[] da; // Free the old memory
    da = temp;
    daCapacity = newCapacity;

    return daCapacity;
}

// Constructor
template <class T>
DynamicArray<T>::DynamicArray(): da{nullptr}, daSize{0}, daCapacity{0}{}

// Destructor
template <class T>
DynamicArray<T>::~DynamicArray(){
    delete[] da;
}

// Push elem to the end of the DynamicArray
template <class T>
void DynamicArray<T>::push(const T &elem){
    size_t newSize = daSize + 1;

    if(newSize >= daCapacity){
        try{
            resize();
        }catch(const std::bad_alloc &e){
            std::cerr << "Did not add element: " << e.what() << std::endl;
            throw;
        }
    }

    da[daSize] = elem;
    daSize = newSize;
}

// Remove the last element from the DynamicArray
template <class T>
T DynamicArray<T>::pop(){
    --daSize;
    return da[daSize];
}

// Return the item at index idx
template <class T>
T DynamicArray<T>::get(const int idx){
    if(idx >= daSize){
        T trash{};
        std::cerr << "Index out of range" << std::endl;
        return trash;
    }

    return da[idx];
}

// Return the size (# of elements) of the DynamicArray
template <class T>
size_t DynamicArray<T>::size() const{
    return daSize;
}

// Return the capacity of the DynamicArray
template <class T>
size_t DynamicArray<T>::capacity() const{
    return daCapacity;
}

// Return true if the DynamicArray is empty and false otherwise
template <class T>
bool DynamicArray<T>::isEmpty() const{
    return daSize == 0;
}

// Print the DynamicArray in the form '[x1, x2, ..., xn]'
template <class T>
void DynamicArray<T>::print() const{
    std::cout << '[';

    if(daSize > 0){
        for(size_t i = 0; i < daSize - 1; ++i) std::cout << da[i] << ", ";
        std::cout << da[daSize - 1];
    }

    std::cout << ']';
}

#endif