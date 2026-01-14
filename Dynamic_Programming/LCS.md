## Longest Common Subsequence

#### Core concept

Finding the longest sequence that appears in the same relative order in two strings, but not necessarily contiguously.

#### Approach

It uses Dynamic Programming by building a 2D table to store the lengths of common subsequences.

#### Complexity

The time complexity is $O(n \times m)$, where $n$ and $m$ are the lengths of the two strings.

#### Step-by-Step Visualization

Imagine 9$X = \text{"ABCBDAB"}$ and 10$Y = \text{"BDCABA"}$.

1. Initialization: Create a table of size 12$(m+1) \times (n+1)$ and fill the first row and column with 0.13
2. Filling the Table: Iterate through each character. If you find a match, the "score" increases.
3. Backtracking: Once the table is full, the bottom-right cell gives you the length. To find the actual string, you start from the bottom-right and move backward:

- If the current characters were a match, move diagonally up-left and record the character.14
- Otherwise, move to the neighbor with the larger value.

3. C Language Implementation Tips
   When you code this in C, keep these technical details in mind:

- 2D Array Allocation: For large strings, use dynamic memory allocation (malloc) to avoid stack overflow, or use a fixed large buffer if you're just practicing.
- The "Plus One" Rule: Since C arrays are 0-indexed, but the DP table needs a "0" row/column for the base case, your table size should be (strlen(X)+1) \* (strlen(Y)+1).
- Space Optimization: Did you know you only actually need two rows of memory to find the length of the LCS? Since we only ever look at the current row and the previous row, you can optimize space from $O(m \times n)$ to $O(n)$
