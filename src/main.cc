#include <iostream>
#include <string>

#include "../include/dynamic-array.h"

using namespace std;

int main(){
    DynamicArray<int> da{};

    /* DynamicArray Tests - Will Change later */ 
    cout << "Empty DynamicArray: ";
    da.print();
    cout << endl;

    da.push(1);
    cout << "DynamicArray: ";
    da.print();
    cout << endl;

    da.push(2);
    cout << "DynamicArray: ";
    da.print();
    cout << endl;

    cout << da.get(0) << endl;

    return 0;
}
