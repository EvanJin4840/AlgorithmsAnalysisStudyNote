- Core Concept: Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than a given limit and the total value is as large as possible.
- 0/1 Knapsack: This version means you cannot break items; you either take an item (1) or leave it (0). It is solved using Dynamic Programming.
- Key Formula: To decide whether to include item $i$ with weight $w_i$ and value $v_i$:$$dp[i][w] = \max(dp[i-1][w], dp[i-1][w-w_i] + v_i)$$

- Why Dynamic Programming? (The Greedy Failure)
  The most common mistake is thinking you can solve this by just picking the most expensive item first.
- Example: Bag capacity is 6kg.
  Item A: 5kg, $60
  Item B: 3kg, $40
  Item C: 3kg, $40
  Greedy Choice: You take Item A ($60). Bag is full. Total = $60.
  DP Choice: You take Item B and C ($40+$40). Total = $80.

- Conclusion: Because items cannot be split, the local "best" choice (Item A) prevents the global "best" combination (B+C). DP explores all combinations efficiently to find the true maximum.
