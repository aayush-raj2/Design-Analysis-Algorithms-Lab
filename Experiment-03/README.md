# Experiment 03: Brute Force String Matching

## Aim
To implement the Brute Force string matching algorithm and find all occurrences of a pattern string within a given text string.

## Description
The Brute Force string matching algorithm checks for the pattern by comparing it character by character at each possible position in the text.

The program displays all starting indices where the pattern is found. If the pattern does not occur, an appropriate message is displayed.

## Algorithm Used
- Brute Force String Matching Algorithm

## Working Principle
- The pattern is aligned with the text at every possible position.
- Characters are compared one by one.
- If all characters match, the position is reported.

## Time Complexity
- Best Case: O(n)
- Worst Case: O(n × m)

Where:
- n = length of text
- m = length of pattern

## Observation
- The algorithm is simple and easy to implement.
- Performance decreases significantly for large strings due to repeated comparisons.

## Conclusion
The Brute Force approach helps in understanding basic string matching concepts but is inefficient for large-scale applications, where advanced algorithms like KMP or Rabin-Karp are preferred.

## Language Used
- C Programming
- C++ Programming

## Platform
- GCC Compiler
- G++ Compiler
