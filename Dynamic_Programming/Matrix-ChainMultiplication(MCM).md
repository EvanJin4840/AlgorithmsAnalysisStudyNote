# Matrix-Chain Multiplication (MCM) Summary

## 1. Problem Definition
* **Goal**: $n$개의 행렬 곱 $A_1, A_2, \dots, A_n$을 계산할 때, 전체 스칼라 곱셈 횟수를 최소화하는 최적의 괄호 배치(Parenthesization)를 찾는 것입니다.
* **Cost Factor**: 행렬 $A (p \times q)$와 $B (q \times r)$의 곱셈 비용은 $p \cdot q \cdot r$로 계산됩니다.
* **Complexity**: 가능한 모든 괄호 배치의 가짓수는 $\Omega(2^n)$에 달하여, 단순 브루트 포스(Brute-force) 탐색으로는 계산이 불가능합니다.

## 2. Dynamic Programming Properties
* **Optimal Substructure**: 문제의 최적 해는 그 내부에 포함된 부분 문제들의 최적 해를 포함하고 있습니다.
* **Overlapping Subproblems**: 재귀적인 솔루션은 동일한 작은 사례들을 반복해서 해결하게 되며, 이를 테이블에 결과를 저장함으로써 최적화할 수 있습니다.

## 3. The Recurrence Relation
$m[i, j]$를 행렬 $A_i$부터 $A_j$까지 곱하는 데 드는 최소 비용이라고 정의합니다:

* **Base Case**: $m[i, i] = 0$ (행렬이 하나일 때는 곱셈이 필요 없음)
* **Recursive Step**: 
  $$m[i, j] = \min_{i \le k < j} \{m[i, k] + m[k+1, j] + p_{i-1}p_k p_j\}$$
  (여기서 행렬 $A_i$의 차원은 $p_{i-1} \times p_i$입니다.)



## 4. Algorithm & Complexity
* **Approach**: 체인 길이 $r$을 2부터 $n$까지 늘려가며 계산하는 바텀업(Bottom-up) 방식입니다.
* **Tables**:
  * `m[i, j]`: 최소 곱셈 비용을 저장합니다.
  * `s[i, j]`: 최적의 비용을 달성한 인덱스 $k$를 저장하여 솔루션을 재구성하는 데 사용합니다.
* **Time Complexity**: 3중 중첩 루프 구조로 인해 **$O(n^3)$**의 시간 복잡도를 가집니다.
* **Space Complexity**: 보조 테이블 저장을 위해 **$O(n^2)$**의 공간 복잡도가 필요합니다.