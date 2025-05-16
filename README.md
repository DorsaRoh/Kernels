# Kernels from Scratch

**Kernel**: the kernel is the core part of your operating system (OS) that sits between your computer's hardware and all other software (like apps or the user interface).

- It abstracts hardware differences, giving software a consistent, standardized environment to run on.

This means developers don’t need to write different code for each type of hardware.

Analogy:
Think of the kernel like your house’s plumbing system.
It doesn’t matter where the water comes out—your shower, kitchen sink, or garden hose—the plumbing makes sure it flows properly, no matter the source.
Similarly, the kernel ensures that software can access and use hardware resources smoothly and reliably.


## 1. Fundamentals & Memory Management

### Pointers and references (C++):

- **Reference**: an alias for an existing object. Is essentially identical to the object being referenced.

   - It does **not** store its own value or memory address. It directly refers to another variable's address in memory.

   Think of it like a nickname for the same person—you’re referring to the same underlying thing.

**Any change made through the reference affects the original variable and vice versa.**


```
// regular types
int             // a normal int type (not a reference)
int&            // a reference to an int object
double&         // a reference to a double object
const int&      // a reference to a const int object
```
<br>

The syntax for references `type& ref` is not to be confused with the address-of operator `&x`, which returns the memory address of variable x.

For example,

```
#include <iostream>

int main()
{
    int x{ 5 };
    std::cout << x << '\n';  // print the value of variable x
    std::cout << &x << '\n'; // print the memory address of variable x

    return 0;
}
```
One run of this prints:
```
5
0027FEA0
```

#### Tip:
The & symbol tends to cause confusion because it has different meanings depending on context:

- When following a type name, & denotes an lvalue reference: `int& ref`.
- When used in a unary context in an expression, & is the address-of operator: `std::cout << &x`.
- When used in a binary context in an expression, & is the Bitwise AND operator: `std::cout << x & y`.


<br>
TODO: Fix this
[See code here](Fundamentals/reference.cpp)

<br><br>


- **Pointer**: tells us the address (in memory) of the object that the pointer is pointing to



<br>

**Additional resources:**
- [What is the Difference Between a Pointer and a Reference C++](https://www.youtube.com/watch?v=sxHng1iufQE&ab_channel=PaulProgramming)