Core Concept: A lossy-less data compression algorithm that assigns variable-length codes to input characters based on their frequencies.

Approach: It uses a Greedy Algorithm. It builds a binary tree (Huffman Tree) by repeatedly merging the two nodes with the lowest frequencies.

Efficiency: Characters that occur more frequently are assigned shorter binary codes, while less frequent characters get longer codes.
