### Matrix Chain Multiplication (MCM)

- Matrix Chain Multiplication is a classic optimization problem that determines the most efficient way to multiply a sequence of matrices. - The goal is not to perform the actual multiplication, but to find the order of parentheses that minimizes the total number of scalar multiplications.1.

* The ProblemSuppose we have a chain of $n$ matrices $\langle A_1, A_2, \dots, A_n \rangle$, where matrix $A_i$ has dimensions $p_{i-1} \times p_i$.
* Matrix multiplication is associative: $(A_1 A_2) A_3 = A_1 (A_2 A_3)$.However, the number of scalar multiplications can vary significantly depending on the order.
* Example:$A_1 (10 \times 100), A_2 (100 \times 5), A_3 (5 \times 50)$$(A_1 A_2) A_3$ costs: $(10 \times 100 \times 5) + (10 \times 5 \times 50) = 5,000 + 2,500 = \mathbf{7,500}$$A_1 (A_2 A_3)$ costs: $(100 \times 5 \times 50) + (10 \times 100 \times 50) = 25,000 + 50,000 = \mathbf{75,000}$
* Result: The first ordering is 10 times faster.
