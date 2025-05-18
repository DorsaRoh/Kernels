/*
POINTERS IN C++
*/


#include <iostream>


/*
We can use pointers in two common ways:

1. To change what the pointer is pointing at (by assigning the pointer a new address)
2. To change the value being pointed at (by assigning the dereferenced pointer a new value)
*/


// First, let’s look at a case where a pointer is changed to point at a different object:

void foo1(){
    int x = 5;
    int* ptr = &x;

    std::cout << ptr << "\n";       // prints memory address of x. prints 0x16d412ff8
    std::cout << *ptr << "\n";      // prints value of x (* dereferences the pointer). prints 5

    
    int y = 6;
    ptr = &y;   // change ptr to point at y

    std::cout << ptr <<"\n";    // prints the memory address of y. prints 0x16d412fec
    std::cout << *ptr << "\n";  // print the value at the address being pointed to (y's address). prints 6
}



// Now let’s look at how we can also use a pointer to change the value being pointed at:

void foo2(){
    int x = 5;
    int* ptr = &x;

    std::cout << x << "\n";     // prints x's value
    std::cout << *ptr << "\n";  // prints the value at the address that ptr is holding (x's address)

    *ptr = 6;   // the object at the address held by ptr (x) changes to value 6 (note that ptr is dereferenced here)

    std::cout << x << "\n";     // prints 6
    std::cout << *ptr << "\n";  // prints 6
}


/*
Basic pointer operations
*/

void foo3(){
    int x = 42;
    int* p = &x;        // pointer p points to x (i.e. points to x's memory address)
    *p = 100;           // change the value at the location p points to (x) to 100
    int* q = p + 1;     // create a new pointer q that points 4 bytes (size of int) beyond p
                        // i.e. take the address in p. add the size of the data type (int = 4 bytes) to it. that's where q should point

    std::cout << *q << "\n";    // prints 1801547072    <- garbage data. content of memory at address you don't own!
    
    /*
    Memory addresses:   0x16b616b0C    0x16b616b10    0x16b616b14
                        ┌───────┐      ┌───────┐      ┌───────┐
                        │  100  │      │ ????? │      │ ????? │
                        └───────┘      └───────┘      └───────┘
                            ▲              ▲
                            │              │
                        p points      q points
                        here          here
    */
    
    
    std::cout << q << "\n";     // prints 0x16b616b10
}


/*
Array access via pointers
*/
void foo4(){
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;     // points to first element (index 0)
    *(ptr + 2) = 9;     // arr[2] is now 9. (ptr+2) moves to element at index 2. *(element at index 2) = 9 reassigns value of that element to 9.
    ptr[3] = 77;        // changes value of element at index 3 to 77. equivalent to *(ptr + 3) = 77


    // when you use the name of an array, it decays **into a pointer** to its first element
    std::cout << arr << "\n";       // prints the address of the first element (0x16d3eaaf0)
    
    
    std::cout << ptr << "\n";       // prints the address of the first element (0x16d3eaaf0)
    std::cout << *(ptr+2) << "\n";  // prints value of element at index 2 (9)

    std::cout << arr[3] << "\n";    // prints 77
    std::cout << ptr[3] << "\n";    // prints 77
}


/*
Memory allocation
*/
#include <vector>

int main(){

    // Manual Dynamic Allocation

    int* dynamicArray = new int[100];       // `new` allocates memory for 100 ints on the heap
    // use dynamicArray like a regular array (e.g., dynamicArray[0] = 5;)
    delete[] dynamicArray;                  // frees the allocated memory

    
    // Automatic Dynamic Allocation (modern C++)
    std::vector<int> vec(100);              // allocates memory for 100 ints, automatically managed
}