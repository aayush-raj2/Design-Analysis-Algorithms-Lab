# String Matching Algorithms (C & C++)

## 📌 Overview
This repository demonstrates two fundamental string matching techniques:

1. Naive String Matching (Brute Force)
2. Knuth-Morris-Pratt (KMP) Algorithm (Optimized)

The goal is to efficiently find occurrences of a **pattern** within a **text**.

--- 

## 🧠 Problem Definition

Given:
- A text string T of length n
- A pattern string P of length m

Find all positions where P occurs in T.

---

# 🔹 1️⃣ Naive String Matching

## 📖 Idea

The naive approach checks for the pattern at **every possible position** in the text.

It does not use any prior knowledge of mismatches.

---

## ⚙️ Working

For each index `i` from 0 to (n - m):

- Compare T[i + j] with P[j] for all j from 0 to m-1
- If all characters match → pattern found at index i
- If mismatch occurs → move to next position (i + 1)

---

## 🔍 Example

Text:    `A B A B D A B A C D A B A B C A B A B`  
Pattern: `A B A B C A B A B`

The algorithm checks:
- Start at index 0 → mismatch
- Start at index 1 → mismatch
- ...
- Eventually finds match at index 10

---

## ⏱ Complexity

- Worst Case: O(n × m)
- Best Case: O(n)

---

## ❌ Limitations

- Repeats unnecessary comparisons
- Inefficient for large inputs
- Performs poorly when text has repeating patterns

---

# 🔹 2️⃣ KMP Algorithm (Knuth-Morris-Pratt)

## 📖 Core Insight

When a mismatch happens, we **should not restart from the beginning of the pattern**.

Instead, we reuse information about previous matches.

👉 This is achieved using the **LPS (Longest Prefix Suffix) array**

---

## 🔍 What is LPS?

LPS[i] = length of the **longest proper prefix** of pattern[0…i]  
which is also a **suffix** of pattern[0…i]

- "Proper" means not equal to the whole string

---

## 🧠 Why LPS Works

When a mismatch occurs at position `j`:
- We already know that characters before `j` matched
- Instead of restarting from `j = 0`
- Jump to `j = LPS[j - 1]`

👉 This avoids rechecking characters

---

## ⚙️ KMP Algorithm Steps

### Step 1: Build LPS Array

Example Pattern: `ABABCABAB`

LPS Array:  
Index: 0 1 2 3 4 5 6 7 8  
Pattern:A B A B C A B A B  
LPS: 0 0 1 2 0 1 2 3 4  

---

### Step 2: Pattern Matching

- Compare text and pattern
- If characters match → move forward
- If mismatch:
  - Use LPS to shift pattern intelligently
  - Avoid restarting from 0

---

## 🔍 Example Insight

Instead of:  
ABABX  
ABABC  

Naive would restart.

KMP says:
👉 “I already matched ABAB → reuse that knowledge”

---

## ⏱ Complexity

- Time Complexity: O(n + m)
- Space Complexity: O(m)

---

## 🚀 Advantages

- No redundant comparisons
- Efficient for large text
- Handles repeated patterns well

---

## ⚠ Limitations

- Slightly complex to implement
- Requires preprocessing (LPS array)

---

# 🔥 Naive vs KMP (Comparison)

| Feature              | Naive           | KMP              |
|---------------------|----------------|------------------|
| Time Complexity     | O(n × m)       | O(n + m)         |
| Efficiency          | Low            | High             |
| Preprocessing       | None           | Required (LPS)   |
| Redundant Work      | High           | Minimal          |
| Best Use Case       | Small inputs   | Large inputs     |

---

# 🎯 Key Takeaways

- Naive = brute force → simple but inefficient  
- KMP = smart skipping → efficient and optimized  
- LPS is the core of KMP  
- Avoiding redundant comparisons is the real goal  

---

# 🎓 Applications

- Text search (Find/Replace)
- Search engines
- DNA sequence matching
- Plagiarism detection
- Compiler design

---

## 👨‍💻 Author
Aayush Raj  
B.Tech CSE – Software Engineering
SRMIST
