# Stack algorithms
C++ implementation of the stack algorithms presented in [Coursera's "Algorithm" course](https://www.coursera.org/learn/algorithms-part1/).

### Files
In no particular order:
* `LinkedStackOfStrings.h` is a stack implementation based on the concept of linked lists. The implementation details are in `LinkedStackOfStrings.h`
* `Node.h` is a node of the linked list and keeps track of its item and of the address of the next item
* `FixedCapacityStackOfStrings.h` implements a stack of fixed and **makes use of an array of pointers** to do so. Since the size of a C++ array can't be declared at run-time but must be known beforehand, this class is implemented as a template that takes the stack size as an argument (meaning it must be instantiated using `FixedCapacityStackOfStrings<stack_size>`, see `main.cpp` for more details). Using an `std::vector` would have been much easier and likely more efficient, but the low-level implementation details wouldn't have been exposed
* `ResizingArrayStackOfStrings` implements a stack whose size is changed when needed. If the stack is full, its size is double. If the number of elements goes below a fourth of the stack's size, the stack gets halved. Since it is necessary to resize the stack at run-time, and since C++ arrays do not implement a C-like behavior (i.e. the size of an array is static in C++), this implementation **makes use of `std::vector`**. It does not, however, exploit methods such as `push_back()`, `emplace_back()`, or `reserve()`, so the underlying logic is still exposed and accessible. 
* `main.cpp` is the main file used to generate the executable
    * Make sure you uncomment the appropriate line to use a particular algorithm
    * The input is obtained from `input.txt`, so make sure it is placed in the executable's folder