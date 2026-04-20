### Activity-Selection Problem

- Problem Statement: The objective is to select a maximum-size set of mutually compatible activities that require exclusive use of a common resource.

- The Greedy Choice: Always choose the activity that leaves the resource available for as many other activities as possible. In practice, this means selecting the activity with the earliest finish time.

- Mathematical Proof (Exchange Argument): If we substitute our greedy choice (earliest finish time) into an existing optimal schedule, the activities remain disjoint, proving that the greedy choice is safely included in a maximum-size subset.

- Efficiency: While DP splits the optimal solution into two subproblems with multiple choices, the greedy approach requires considering only one choice and leaves only one subproblem to solve. Assuming activities are sorted by finish time, the iterative algorithm runs in $\Theta(n)$ time.