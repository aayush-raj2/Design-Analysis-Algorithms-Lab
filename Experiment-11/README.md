# Randomized Quick Sort (C & C++)

## 📌 Overview
This repository contains implementations of **Randomized Quick Sort**, an optimized version of Quick Sort that uses random pivot selection to improve performance.

Unlike standard Quick Sort, which can degrade to O(n²), Randomized Quick Sort ensures better average performance by reducing the probability of worst-case scenarios.

---

## 🧠 Approach Used

Divide and Conquer

Algorithm:
1. Choose a random pivot element
2. Partition the array around the pivot
3. Recursively sort left and right subarrays

---

## ⏱ Complexity

Best Case: O(n log n)  
Average Case: O(n log n)  
Worst Case: O(n²) (very unlikely due to randomization)

Space Complexity: O(log n) (recursion stack)

---

## 🚀 Features

- Random pivot selection
- In-place sorting
- Improved performance reliability
- Implemented in:
  - C
  - C++

---

## 📂 Project Structure
randomized-quick-sort/  
│  
├── C/  
│ └── randomized_quicksort.c  
│  
├── CPP/  
│ └── randomized_quicksort.cpp  
│  
└── README.md  

---

## ⚠ Limitations

- Worst case still exists (but rare)
- Recursive implementation uses stack space

---

## 🎓 Suitable For

- Design and Analysis of Algorithms
- Divide and Conquer Techniques
- Performance Optimization Study

---

## 👨‍💻 Author
Aayush Raj  
B.Tech CSE – Software Engineering
