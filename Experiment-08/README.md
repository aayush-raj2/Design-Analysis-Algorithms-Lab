# Longest Common Subsequence (LCS) – C & C++

## 📌 Overview
This repository contains implementations of the Longest Common Subsequence (LCS) problem using Dynamic Programming.

The LCS problem finds the longest subsequence common to two sequences.

Unlike substring, subsequence does NOT require consecutive characters.

Example:
String 1: ABCDGH
String 2: AEDFHR
LCS: ADH
Length: 3

---

## 🧠 Approach Used

Dynamic Programming (Bottom-Up)

Recurrence Relation:

If X[i-1] == Y[j-1]:
    dp[i][j] = 1 + dp[i-1][j-1]
Else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

---

## ⏱ Complexity

Time Complexity: O(n × m)  
Space Complexity: O(n × m)

Where:
n = length of first string  
m = length of second string  

---

## 🚀 Applications

- DNA sequence analysis
- Version control (diff tools)
- Text comparison
- Bioinformatics
- Pattern recognition

---

## 📂 Project Structure
longest-common-subsequence/  
│  
├── C/  
│ └── lcs.c  
│  
├── CPP/  
│ └── lcs.cpp  
│  
└── README.md  

---

## 🎓 Suitable For

- Design and Analysis of Algorithms
- Dynamic Programming Practice
- Coding Interviews
- Lab Submission

---

## 👨‍💻 Author
Aayush Raj  
B.Tech CSE – Software Engineering
