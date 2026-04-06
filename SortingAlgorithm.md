### Heap Sort
* **Concept:** A comparison-based sorting algorithm that uses a **Binary Heap** data structure.
* **Mechanism:** It builds a Max Heap, repeatedly swaps the root (largest value) with the last element, and then "heapifies" the remaining structure.
* **Pros:** It guarantees $O(n \log n)$ time complexity regardless of the input distribution.
* **Cons:** It is an **unstable** sort, meaning it does not preserve the relative order of duplicate items.

---

### Insertion Sort
* **Concept:** A simple sorting algorithm that builds the final sorted array one item at a time.
* **Mechanism:** It picks an element and finds its correct position within the already-sorted part of the array, shifting other elements as needed.
* **Pros:** Highly efficient for **small datasets** or **nearly sorted** data. It is a **stable** and in-place algorithm.
* **Cons:** Very slow for large, unsorted datasets due to its $O(n^2)$ average/worst-case performance.