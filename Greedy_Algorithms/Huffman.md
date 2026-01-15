Core Concept: A lossy-less data compression algorithm that assigns variable-length codes to input characters based on their frequencies.

Approach: It uses a Greedy Algorithm. It builds a binary tree (Huffman Tree) by repeatedly merging the two nodes with the lowest frequencies.

Efficiency: Characters that occur more frequently are assigned shorter binary codes, while less frequent characters get longer codes.

Step-by-Step Construction Process

To create a Huffman Tree and its resulting codes, the algorithm follows these steps:

1. Frequency Analysis: Count the occurrences (frequency) of every character in the input string.

2. Leaf Node Creation: Create a leaf node for each character and add it to a Priority Queue (ordered by frequency).

3. Tree Building (Greedy Approach):

- While there is more than one node in the queue:

* Remove the two nodes with the lowest frequencies.
* Create a new internal node with a frequency equal to the sum of the two nodes.
* Make the two nodes children of this new node.
* Insert the new node back into the Priority Queue.

4. Assigning Bits: Once the tree is finished, the root represents the entire dataset.

- Assign 0 to every left branch and 1 to every right branch.

5. Code Generation: The code for each character is the sequence of bits on the path from the root to that character's leaf.
