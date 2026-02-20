# Strassen Matrix Multiplication (C & C++)

## 📌 Overview
This repository contains implementations of **Strassen’s Matrix Multiplication Algorithm** using the Divide and Conquer paradigm.

Strassen’s algorithm improves the classical matrix multiplication time complexity from:

O(n³)

to

O(n^log₂7) ≈ O(n^2.81)

It reduces the number of recursive multiplications from 8 to 7, trading multiplications for additions.

---

## 🚀 Features

- Divide and Conquer approach
- Recursive implementation
- Works for square matrices (n × n)
- Padding required if n is not a power of 2
- Implemented in:
  - C
  - C++

---

## 🧠 Algorithm Steps

1. Divide matrix A and B into 4 submatrices each.
2. Compute 7 recursive matrix multiplications (M1–M7).
3. Combine the results into final matrix C.

Recurrence Relation:

T(n) = 7T(n/2) + O(n²)

Using Master Theorem:

T(n) = O(n^log₂7) ≈ O(n^2.81)

---

## 📂 Project Structure
│   
├── C/   
│ └── strassen.c   
│   
├── CPP/   
│ └── strassen.cpp   
│   
└── README.md   

---

## ⚠ Limitations

- Higher constant overhead than classical multiplication
- Not efficient for small matrices
- Requires additional memory
- Best suited for large matrices

---

## 🎓 Suitable For

- Design and Analysis of Algorithms
- Data Structures & Algorithms
- Academic Lab Submission
- Complexity Analysis Study

---

## 👨‍💻 Author
Aayush Raj  
B.Tech CSE – Software Engineering
