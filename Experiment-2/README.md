# Experiment 02: Bubble Sort and Insertion Sort

## Aim
To design and implement a menu-driven program to sort a given set of integers using Bubble Sort and Insertion Sort algorithms and compare their CPU execution time with advanced sorting techniques.

## Description
This experiment demonstrates the working of two basic sorting algorithms:
- Bubble Sort
- Insertion Sort

The program accepts a minimum of 10000 integers and sorts them in ascending order based on the user's choice. CPU execution time is measured using the `clock()` function.

## Algorithms Used
1. Bubble Sort
2. Insertion Sort

## CPU Time Calculation
CPU Time is calculated using the formula:  
CPU Time = (end - start) / CLOCKS_PER_SEC


## Time Complexity
| Algorithm | Best Case | Average Case | Worst Case |
|---------|-----------|--------------|------------|
| Bubble Sort | O(n) | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) | O(n²) |

## Observation
- Bubble Sort performs very poorly for large datasets.
- Insertion Sort performs slightly better but still inefficient for n ≥ 10000.
- Advanced sorting algorithms such as Heap Sort and AVL Tree-based sorting perform significantly faster with O(n log n) complexity.

## Conclusion
This experiment highlights the performance limitations of basic sorting algorithms when handling large datasets and emphasizes the importance of advanced data-structure-based sorting techniques.

## Language Used
- C Programming
- C++ Programming

## Platform
- GCC Compiler
- G++ Compiler
