In this version, items are like "items in a sack" (e.g., rice, gold dust, or liquid). You can take a fraction of an item.

The Strategy: This is solved using a Greedy Algorithm.

The Logic:

Calculate the Value-per-Weight ratio for each item (Price / Weight).

Sort items in descending order of this ratio.

Take as much of the best item as possible. If the bag isn't full, take a fraction of the next best item.

Why it's Greedy: Because you can take fractions, it is always mathematically optimal to prioritize the "most valuable per gram" items.

- Problem Characteristics

* Items are divisible (like rice, gold dust, oil).
* You can take any fraction of an item.
* The goal is to maximize total value without exceeding the knapsack’s weight capacity.
