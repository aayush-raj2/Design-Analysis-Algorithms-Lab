# N-Queens Problem (Backtracking) – C & C++

## 📌 Overview
This repository contains implementations of the **N-Queens Problem** using Backtracking.

The goal is to place N queens on an N×N chessboard such that:
- No two queens attack each other
- No two queens share the same row, column, or diagonal

---

## 🧠 Approach Used

Backtracking (Constraint Satisfaction)

Algorithm:
1. Place a queen column by column
2. Check if the position is safe:
   - No queen in same row
   - No queen in upper diagonal
   - No queen in lower diagonal
3. If safe → place queen and move to next column
4. If not safe → backtrack and try next position

---

## ⏱ Complexity

Time Complexity: O(N!) (worst case)  
Space Complexity: O(N²)

---

## 🚀 Features

- Recursive backtracking
- Prints one valid solution
- Works for any N ≥ 4

---

## 📂 Project Structure
n-queens-problem/  
│  
├── C/  
│ └── n_queens.c  
│  
├── C++/  
│ └── n_queens.cpp  
│  
└── README.md  

---

## 🎓 Suitable For

- Design and Analysis of Algorithms
- Backtracking Problems
- Constraint Satisfaction Problems
- Coding Interviews

---

## 👨‍💻 Author
Aayush Raj  
B.Tech CSE – Software Engineering
