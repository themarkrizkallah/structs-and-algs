#ifndef _SORTER_H_
#define _SORTER_H_
#include <vector>

template <class T>
class Sorter final{
    std::vector<T> array;

    // Merge sort helpers
    void mergeSort(std::vector<T> &helper, int low, int high);
    void merge(std::vector<T> &helper, int low, int middle, int high);

public:
    // Constructor
    explicit Sorter(const std::vector<T> array);

    // Sorting algorithms
    void selectionSort(); // O(n^2)
    void bubbleSort(); // O(n^2)
    void mergeSort(); // O(nlogn)
    // void quickSort(); // TODO - O(nlogn)

    // Prints the elements of the array
    void print() const; // O(n)
};

// Constructor
template <class T>
Sorter<T>::Sorter(const std::vector<T> array): array{array}{}

// Selection sort
template <class T>
void Sorter<T>::selectionSort(){
    const size_t length = array.size();
    size_t minIdx;

    if(length > 0){
        for(size_t i = 0; i < length - 1; ++i){
            minIdx = i;

            for(size_t j = i + 1; j < length; ++j){
                if(array[j] < array[minIdx]) minIdx = j;
            }

            if(minIdx != i){
                T temp = array[i];
                array[i] = array[minIdx];
                array[minIdx] = temp;
            }
        }
    }
}

// Bubble sort (with optimization)
template <class T>
void Sorter<T>::bubbleSort(){
    int length = array.size();
    bool isSwapped = true;

    while(isSwapped){
        isSwapped = false;

        for(int i = 0; i < length - 1; ++i){
            int j = i+1;

            if(array[i] > array[j]){
                T temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                isSwapped = true;
            }
        }
        --length;
    }
}

// Merge sort
template <class T>
void Sorter<T>::mergeSort(){
    const int length = array.size();
    std::vector<T> helper(length);

    mergeSort(helper, 0, length - 1);
}

// Merge sort helpers
template <class T>
void Sorter<T>::mergeSort(std::vector<T> &helper, int low, int high){
    if(low < high){
        int middle = (low + high) / 2;

        mergeSort(helper, low, middle);
        mergeSort(helper, middle + 1, high);
        merge(helper, low, middle, high);
    }
}

template <class T>
void Sorter<T>::merge(std::vector<T> &helper, int low, int middle, int high){
    for(int i = low; i <= high; ++i) helper[i] = array[i];

    int currIdx = low;
    int leftIdx = low;
    int rightIdx = middle + 1;

    while(leftIdx <= middle && rightIdx <= high){
        if(helper[leftIdx] < helper[rightIdx]){
            array[currIdx++] = helper[leftIdx];
            ++leftIdx;
        }else{
            array[currIdx++] = helper[rightIdx];
            ++rightIdx;   
        }
    }

    int remaining = middle - leftIdx;
    for(int i = 0; i <= remaining; ++i) array[currIdx + i] = helper[leftIdx + i];
}

// Prints the elements of array in the form [x1, x2, ..., xn]
template <class T>
void Sorter<T>::print() const{
    const int length = array.size();

    std::cout << '[';
    for(int i = 0; i < length - 1; ++i)  std::cout << array[i] << ", ";
    if(length > 0) std::cout << array[length - 1];
    std::cout << ']';
}

/*
    // Sorter tests
    const vector<int> empty = {};
    const vector<int> array1 = {3, 2, 1, 5, 6};
    const vector<int> sorted = {1, 2, 3, 4};

    Sorter<int> sort1(empty);
    Sorter<int> sort2(array1);
    Sorter<int> sort3(sorted);

    cout << "Before sorting:" << endl;

    cout << "Empty: ";
    sort1.print();
    cout << endl;

    cout << "Array #1: ";
    sort2.print();
    cout << endl;

    cout << "Sorted: ";
    sort3.print();
    cout << endl;

    sort1.mergeSort();
    sort2.mergeSort();
    sort3.mergeSort();

    cout << "After sorting:" << endl;
    cout << "Empty: ";
    sort1.print();
    cout << endl;

    cout << "Array #1: ";
    sort2.print();
    cout << endl;

    cout << "Sorted: ";
    sort3.print();
    cout << endl;
*/
#endif