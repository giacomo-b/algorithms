# Queues algorithms
C++ implementation of the queues-specific algorithms presented in [Coursera's "Algorithm" course](https://www.coursera.org/learn/algorithms-part1/).

### Files
In no particular order:
* `LinkedQueueOfStrings.h` is a queue implementation based on the concept of linked lists. As opposed to the a stack implemented with linked lists, this implementation needs to keep track both of the first and last node
* `Node.h` is a node of the linked list and keeps track of its item and of the address of the next item
* `ResizingQueueOfStrings` implements a queue whose size is changed when needed. If the queue is full, its size is doubled. If the number of elements goes below a fourth of the queues's size, the stack gets halved and its elements are pushed to the first element again. In addition to this, if the tail of the queue equals the capacity of the array but the tail is not pointing to the first element of the array, all the elements of the queue need to be shifted back to zero. Since it is necessary to resize the queue at run-time, and since C++ arrays do not implement a C-like behavior (i.e. the size of an array is static in C++), this implementation **makes use of `std::vector`**. It does not, however, exploit methods such as `push_back()`, `emplace_back()`, or `reserve()`, so the underlying logic is still exposed and accessible.
* `main.cpp` is the main file used to generate the executable
    * Make sure you uncomment the appropriate line to use a particular algorithm
    * The input is obtained from `input.txt`, so make sure it is placed in the executable's folder