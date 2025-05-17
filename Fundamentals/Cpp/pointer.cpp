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

int foo1(){
    int x = 5;
    int* ptr = &x;

    std::cout << ptr << "\n";       // prints memory address of x. prints 0x16d412ff8
    std::cout << *ptr << "\n";      // prints value of x (* dereferences the pointer). prints 5

    
    int y = 6;
    ptr = &y;   // change ptr to point at y

    std::cout << ptr <<"\n";    // prints the memory address of y. prints 0x16d412fec
    std::cout << *ptr << "\n";  // print the value at the address being pointed to (y's address). prints 6
    
    return 0;
}



// Now let’s look at how we can also use a pointer to change the value being pointed at:

int main(){
    int x = 5;
    int* ptr = &x;

    std::cout << x << "\n";     // prints x's value
    std::cout << *ptr << "\n";  // prints the value at the address that ptr is holding (x's address)

    *ptr = 6;   // the object at the address held by ptr (x) changes to value 6 (note that ptr is dereferenced here)

    std::cout << x << "\n";     // prints 6
    std::cout << *ptr << "\n";  // prints 6

    return 0;
}
