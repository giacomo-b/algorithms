# Union-Find algorithms
C++ implementation of the Union-Find algorithms presented in [Coursera's "Algorithm" course](https://www.coursera.org/learn/algorithms-part1/).

### Files
In no particular order:
* `UnionFind.h` implements all the Union-Find algorithms.
    * `UnionFind` is an abstract class which defines the API common to all UF algorithms.
    * `QuickFind` inherits from `UnionFind`
    * `QuickUnion` inherits from `UnionFind`
    * `WeightedQuickUnion` inherits from `QuickUnion`
    * `PathCompressionWeightedQuickUnion` inherits from `WeightedQuickUnion`
* `Timer.h` is a header used to get the execution time of a particular scope (makes use of RAII). To use, just write `Timer name_of_timer;` and it will automatically destroy at the end of the scope in which it has been declared.
* `main.cpp` is the main file used to generate the executable
    * Make sure you uncomment the appropriate line to test a particular algorithm
    * Make sure the suppress the output by commenting the appropriate line if you want to make sense of the timer results.
    * The input is obtained from `input.txt`
* `input-generator.py` is an auxiliary script that generates a random input file of the desired size. Just run it with `python input-generator.py` and it will ask to provide the number of nodes and entries.

**Note**: *I changed the* `union` *method name to* `join` *because of the C++ reserved keyword.*