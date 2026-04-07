# Understanding Dynamic Programming (DP)

## 1. The Meaning of "Programming"
In the context of **Dynamic Programming**, "Programming" does not refer to writing code in languages like C++ or Python. Instead, it refers to a **tabular method**—specifically, the act of "planning" or "scheduling" by recording values in a table.

**Definition:** Dynamic Programming is a **mathematical methodology** used to find an optimal solution by breaking down a complex problem into smaller subproblems and storing their results in a **Table** for future use.

---

## 2. Core Properties of DP
* **Optimal Substructure:** This property states that an optimal solution to a global problem can be constructed from the optimal solutions of its local subproblems.
    * **Key Concept:** If you decompose a large-scale optimal solution, it consists of optimal solutions to smaller, nested subproblems.
* **Overlapping Subproblems:** DP is applicable when a recursive algorithm for a problem visits the same subproblems repeatedly.
    * **Strategy:** Instead of recomputing the same subproblems multiple times, DP stores the results in a table (often referred to as an **m-table** or **Memorization table**) and reuses them.
    * **Core Strategy:** **Memorization** (storing results to avoid redundant calculations).

---

## 3. Principle of Optimality
The **Principle of Optimality** is a fundamental design paradigm of DP. It asserts that if a total path (or sequence of decisions) is optimal, then any intermediate segment of that path (from any mid-point to the destination) must also be an optimal path for that specific sub-segment.

---

## 4. Steps for Developing a DP Algorithm
When solving an optimization problem using DP, the following four steps are typically followed:

### Step 1: Characterize the structure of an optimal solution.
As an example, consider the **Matrix Chain Multiplication** problem where we calculate the product of matrices $A_i$ through $A_j$ (where $i < j$):
1.  To compute the product $A_i \dots A_j$, we must split the sequence into two parts: $A_i \dots A_k$ and $A_{k+1} \dots A_j$ for some integer $k$ ($i \le k < j$).
2.  The matrices must be parenthesized as $(A_i \dots A_k)(A_{k+1} \dots A_j)$.
3.  The total cost to compute $A_{i..j}$ is the sum of:
    * The cost of computing the first sub-chain $A_{i..k}$.
    * The cost of computing the second sub-chain $A_{k+1..j}$.
    * The cost of multiplying the two resulting matrices together.
4.  **Efficiency:** This reduces the time complexity from $O(2^n)$ to $O(n^3)$.

### Step 2: Recursively define the value of an optimal solution.
In this step, we establish a mathematical formula for the minimum cost.
* Let $m[i, j]$ be the minimum number of scalar multiplications required to compute the product of matrices $A_i \dots A_j$.
* $m[i, j]$ can be defined recursively as follows:
    $$m[i, j] = \begin{cases} 0 & \text{if } i = j \\ \min_{i \le k < j} \{m[i, k] + m[k+1, j] + p_{i-1}p_kp_j\} & \text{if } i < j \end{cases}$$

### Step 3: Compute the value of an optimal solution in a bottom-up fashion.
Instead of solving the recurrence relation recursively (which is inefficient), we use a **bottom-up approach** with a table.
* By using a table to store intermediate results, we compute the optimal cost starting from the smallest subproblems (chain length 1, then 2, etc.) and moving up to the total problem.

### Step 4: Construct an optimal solution from the computed information.
Knowing the cost is not enough; we need to know the actual sequence of multiplications.
* The table $s[1..n-1, 2..n]$ provides the necessary information for the optimal parenthesization.
* Each entry $s[i, j]$ stores the value of $k$, which represents the **optimal split point** between $A_k$ and $A_{k+1}$ for the product $A_i A_{i+1} \dots A_j$.
* The final multiplication for $A_{1..n}$ is $(A_1 \dots A_{s[1,n]}) (A_{s[1,n]+1} \dots A_n)$. We can recursively determine the entire multiplication sequence.

---

## Supplementary Notes

### 1. What is P in Matrix Chain Multiplication?
To multiply two matrices, the number of columns in the first matrix must match the number of rows in the second. When listing dimensions in sequence, these values overlap.
* The list $P$ simplifies this by removing redundant values and recording only the "boundary" dimensions.
* Since we need the number of rows for the very first matrix (the left edge), the list $P$ starts from $P_0$ and goes up to $P_n$.
* **General Formula:** The dimension of matrix $A_i$ is defined as $P_{i-1} \times P_i$.

### 2. The M-list (Meaning of the m-table)
The m-table stores the minimum costs of previously calculated subproblems.
* For example, $m[i, k]$ represents the cost already incurred to assemble matrices $A_i$ through $A_k$.
* **The Merging Cost:** We must add $P_{i-1} \times P_k \times P_j$ to the sum of subproblems. This term represents the final cost of multiplying the two resulting matrices into one.
* Note that all values in the M-list are **scalars** (single numerical values).

### 3. What is a Brute-Force Algorithm?
* A **Brute-Force** approach involves exhaustively checking every single possible case from beginning to end.
* While simple, it is highly inefficient. By using **Dynamic Programming**, we save the solutions of smaller subproblems in a Table, allowing us to significantly reduce the time and cost required to solve the problem.