# Longest Common Subsequence (LCS)

### 1. Core Concept & Definitions
* **Definition**: Finding the longest sequence that appears in the same relative order in two strings, but not necessarily contiguously.
* **i-prefixes ($X_i$)**: An $i$-prefix of $X$ is the first $i$ characters of $X$. 
* **Base Case ($X_0, Y_0$)**: $X_0$ and $Y_0$ represent empty sequences (length 0). This is why the DP table needs an extra "0" row and column.

### 2. Mathematical Logic (Theorem 15.1)
* **The Principle**: The algorithm uses optimal substructure to solve LCS by comparing prefixes step by step.

* **Case 1: Match ($x_i = y_j$)**
  - If the current characters match, this character **must** be part of the LCS. 
  - Formula: $c[i, j] = c[i-1, j-1] + 1$.

* **Case 2: Mismatch ($x_i \neq y_j$)**
  - If they don't match, we take the maximum value from the best previous subproblems.
  - Formula: $c[i, j] = \max(c[i-1, j], c[i, j-1])$. (This preserves the best record found so far).

---

### 3. Step-by-Step Table Mechanics
* **Step 1: Initialization**
  - Create a table of size $(m+1) \times (n+1)$.
  - Fill the first row ($i=0$) and column ($j=0$) with **0** to represent the empty prefix base case.

* **Step 2: Filling the Table & Navigation ($b[i, j]$)**
  - **Diagonal ($\nwarrow$)**: Recorded when a match is found. It signals a score increase.
  - **Up ($\uparrow$) & Left ($\leftarrow$)**: Recorded during a mismatch. They point to the neighbor with the larger value to maintain the maximum length.

* **Step 3: Backtracking (Finding the String)**
  - Start from the bottom-right cell $b[m, n]$.
  - If the arrow is **Diagonal ($\nwarrow$)**, record the character and move up-left.
  - Otherwise, follow the **Up** or **Left** arrow to the neighbor.
  - **Final Result**: Reverse the collected characters to get the correct LCS string.

### 4. Complexity & Performance
* **Time Complexity**: $\Theta(m \times n)$ because every cell in the table must be computed.
* **Space Complexity**: $\Theta(m \times n)$ to store both the length ($c$) and direction ($b$) tables for backtracking.

* **Bottom-up (Tabulation) vs. Memoization**:
  - **Bottom-up**: Generally faster by a constant factor as it avoids recursive function call overhead.
  - **Memoization**: More efficient **only if** a small subset of subproblems is required.

### 5. C Language Implementation Tips
* **2D Array Allocation**: Use `malloc` for large strings to avoid stack overflow.
* **The "Plus One" Rule**: Your table size must be `(strlen(X)+1) * (strlen(Y)+1)` to accommodate the 0-indexed base cases.
* **Space Optimization**: If you only need the **length** (not the string), you can optimize space to $O(min(m, n))$ by only keeping the current and previous rows in memory.