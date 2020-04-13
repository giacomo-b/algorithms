# Algorithms
C++ implementation of the algorithms and data structures presented in [Coursera's "Algorithm" course](https://www.coursera.org/learn/algorithms-part1/).

## Why?
I enjoy coding in C++.

In the original course, all the algorithms are implemented in Java and all the lessons use Java to present the algorithms APIs.
Since I wrote the algorithms in C++ for fun and to experiment with some of the language features, I thought it would be worth sharing them mainly for educational purpose, in the hope that they will come handy to someone else.

## How to
I divided the algorithms according to the order in which they are presented in the course. To run them, do the following:

* Clone the repo with ```git clone https://github.com/giacomo-b/algorithms.git``` or, as an alternative, download as a .zip file.
* Navigate to the appropriate folder and issue the command ```make``` or `make all`. If you wish to use another compiler you can either edit the `Makefile` or import the files into you favorite IDE.

I used the same general-purpose `Makefile` in every folder, so feel free to edit them if appropriate.

Please refer to the README files inside each folder for additional information.

I also uploaded the slide of the course, which are publicly available on [Coursera](https://www.coursera.org/learn/algorithms-part1/).

## Be warned
Please note that performance is not the priority (clarity is) since these files are intended for educational purpose. However, whenever there is particular room for improvement, I will make sure to specify that in the README file.

In some circumstances I deliberately used a less-efficient C++ structure for certain operation in order to have a more low-level control of the algorithm logic. One such case is the use of C-like arrays in some of the files instead of the more appropriate `std::vector` type. Using operations such as `push_back` or `resize` would likely be more efficient, but less appropriate nonetheless since it wouldn't give control over the underlying logic.

Similarly, not all exceptions are handled. Again, this is because these algorithms are intended to be as clear as possible for someone who is trying to implement them. If you have to use them for real applications, make sure you always test for the appropriate exceptions and make as may assertions as possible while debugging.