#include <iostream>


/*
Note: The convention `int& ref;`, with the ampersand after the type,
emphasizes that "ref is a variable of type int&" (reference to int).
*/

int foo1(){

    int x= 5;       // x is a normal integer variable
    int& ref = x;   // ref is a reference variable to the variable x

    std::cout << x << "\n";         // print the value of x (5)
    std::cout << ref << "\n";       // print the value of x via ref

    return 0;
}



int foo2(){

    int x = 5;      // normal integer variable
    int& ref = x;   // ref is now an alias for variable x

    std::cout << x << ref << "\n";      // prints 55

    x = 6;      // x now has value 6. 
                // ref points to the same address in memory as x, so ref is now 6 too.

    std::cout << x << ref << "\n";      // prints 66

    ref = 7;    // the object being referenced (x) now has value 7
    
    std::cout << x << ref << "\n";      // prints 77

    return 0;
}


/*
Consider the following variables.alignas

int var;                
int& ref1 = var;        // a reference bound to var
int& ref2 = ref1;       // a reference bound to var

Because `ref2` (a reference) is initialized with `ref1` (a reference), you might
be tempted to conclude `ref2` is a reference to a reference. It is not. Because `ref1` 
is a reference to `var`, which used in an expression (such as an initializer), `ref1`
evaluates to `var`. So `ref2` is just a normal reference as indicated by its type `int&`),
bound to `var`.
*/




/*
References seem useless, why use them if they are simply aliases of an existing variable?

One way to avoid making an expensive copy of an argument when calling a function is to use
pass by reference instead of pass by value. When using pass by reference, we declare a function parameter as a 
reference type rather than as a normal type.

In other words, pass by reference allows us to pass arguments to a function without 
making copies of those arguments each time the function is called.

For example, see the function below:
*/


void printValue(std::string& y){      // parameter's type is reference type, not normal type      
    std::cout << y << "\n";
}


int foo3(){
    std::string x = "Hello world!";

    printValue(x);      // x is now passed by reference into reference parameter y

    return 0;
}



/*
The following program demonstrates that a value parameter is a separate object from the 
argument, while a reference parameter is treated as if it were the argument.


One run of this program produced the following output:

The address of x is: 0x16eebb008
The address of the value parameter is: 0x16eebafdc
The address of the reference parameter is: 0x16eebb008


We can see that the argument has a different address  than the value parameter, meaning that the value
parameter is a different object. Since they have separate memory addresses, in order for the value
parameter to have the same value as the argument, the argument's value must be copied into memory held by
the value parameter. 

On the other hand, we can see that taking the address of the reference parameter yields an address identical to 
that of the argument. This means that the reference parameter is being treated as if it were the same object as the argument.

*/

void printAddresses(int val, int& ref){
    std::cout << "The address of the value parameter is: " << &val << "\n";
    std::cout << "The address of the reference parameter is: " << &ref << "\n";
}

int main(){
    int x = 5;
    std::cout << "The address of x is: " << &x << "\n";
    printAddresses(x,x);

    return 0;
}
