### The Limitations of Dynamic Programming (DP)
- Exhaustive Search: Algorithms like Matrix Chain Multiplication ($O(n^3)$) and Longest Common Subsequence ($O(mn)$) are relatively inefficient. They blindly and exhaustively check all possible choices to compute an optimal solution.

- The Need for Restriction: To improve efficiency, there is a need to find ways to decide the best choice immediately or, at least, restrict the number of choices that must be tried.

## The Greedy Strategy
- Local Optimum: A design strategy that makes the choice that looks best at the current moment, without considering its implications for future subproblems.

- Top-down vs. Bottom-up: While DP solves problems in a bottom-up manner (depending on solutions to subproblems), Greedy algorithms operate top-down: they make an immediate choice and then solve the remaining subproblem.

- Global Optimum: Making locally optimal choices does not always lead to globally optimal solutions, but it comes up with the global optimum in many specific cases.

* Example: The Coin Change Problem

- Objective: Make a specific amount of money (e.g., 1,380 won) using the minimum number of coins.

- Available Coins: 500, 100, 50, and 10 won.

- The Greedy Choice: Always select the largest possible coin denomination first.

###### Execution: 
- $1,380 - (500 \times 2) = 380$
- $380 - (100 \times 3) = 80$
- $80 - (50 \times 1) = 30$
- $30 - (10 \times 3) = 0$

### Activity-Selection Problem

- Problem Statement: The objective is to select a maximum-size set of mutually compatible activities that require exclusive use of a common resource.

- The Greedy Choice: Always choose the activity that leaves the resource available for as many other activities as possible. In practice, this means selecting the activity with the earliest finish time.

- Mathematical Proof (Exchange Argument): If we substitute our greedy choice (earliest finish time) into an existing optimal schedule, the activities remain disjoint, proving that the greedy choice is safely included in a maximum-size subset.

- Efficiency: While DP splits the optimal solution into two subproblems with multiple choices, the greedy approach requires considering only one choice and leaves only one subproblem to solve. Assuming activities are sorted by finish time, the iterative algorithm runs in $\Theta(n)$ time.