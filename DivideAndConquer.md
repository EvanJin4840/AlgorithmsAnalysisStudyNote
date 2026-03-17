##### What is the Recurrence Equation?

In mathematics, a recurrence relation is an equation according to which the nth term of sequence of numbers is equal to some combination of the previous terms.
“자신을 정의할 때 다시 자신을 사용하는 수학 식”으로, 어떤 알고리즘이 문제를 해결하는 데 걸리는 시간 T(n)을 계산하기 위해서 사용합니다.

- 식의 구성 요소 정리
T(n) = 전체 시간 복잡도 (크기가 n인 문제를 해결하는 데 드는 총 시간입니다.)
A = 부분 문제의 개수 (문제를 몇 개의 조각으로 쪼개서 다시 처리할 것인가? [divide])
n/b = 부분 문제의 크기 (한 조각의 크기가 원래보다 얼마나 작아졌는가?[얼마나 잘게 썰었는가?])
f(n) = 추가 작업 비용 (문제를 쪼개고[divide], 나중에 합치는[Combine] 데 드는 시간.)

##### What is the Recursion Tree?
Root(맨 위): 현재 단계에서 발생하는 순수한 노동량 [분할 및 결합 비용] f(n)
Branch(가지): 문제를 a개로 쪼개는 과정
Depth(깊이): 문제가 1이 될 때까지 계속 쪼개지는 층수 (logb n)
Leaf(맨 아래): 더 이상 쪼갤 수 없는 가장 작은 문제들

## Solving Recurrence Equations

### Substitution method(치환법)
치환법은 다음 두 단계로 진행됩니다.
1.	해의 모양을 추측한다.
2.	상수들의 값을 찾아내기 위해 수학적 귀납법을 사용하고 그 해가 제대로 동작함을 보인다.
참고:
- 치환법을 사용해 상한이나 하한 어느 쪽도 구할 수 있습니다.
- 변수를 바꿈으로 점화식을 좀 더 간단하게 할 수 있습니다.
- 귀납법으로 증명이 잘 안되는 경우에는, 저차항을 빼서 그 추측식을 바꾸면 해결되는 경우가 많습니다.
### Recursion-tree method (재귀 트리 방법)
점화식이 쪼개지는 과정을 직접 그림(트리)으로 그려서 눈으로 보며 총비용을 계산하는 직관적인 방법입니다.
각 노드가 재귀 호출되는 하위 문제 하나의 비용을 나타냅니다.
단계 설명
1.	루트 노드 그리기(트리의 맨 꼭대기)
2.	하위 문제로 확장 시키기(가지치기)
3.	더 이상 쪼갤 수 없을 때까지 계속 반복하며 트리를 끝까지 그려 내려가기
4.	전부 더하기
즉, 재귀 트리는 문제 전체를 노드로 펼쳐 놓고, 각 층의 비용 합(가로) * 트리의 높이(세로)를 계산해 총 시간 복잡도를 구하는 시각적인 방법입니다.
### Master method (마스터 방법)
F(n)과 n^(logb a)를 비교하여
Case 1: f(n)의 성장 속도(growth rate)가 더 작은 경우
Case 2: F(n)과 n^(logb a)의 성장 속도가 같은 경우
Case 3: f(n)의 성장 속도가 더 큰 경우
로 나누어 Master Theorem에 따라 f(n)과 T(n)이 결정됩니다.
단, polynomially하게 작거나 크지 않은 경우에는 적용이 불가능합니다.

Ex) T(n) = 2T(n/2) + nlog2 n

- 적용이 안 되는 이유:
리프 노드의 파워는 n입니다.
N log n이 n보다는 크지만, 다항식 수준으로 크지 않습니다. (log 차이는 다항식 차이보다 훨씬 작기 때문에 격차(Epsilon)이 존재하지 않기 때문에, 표준 마스터 정리[Master Theorem]로 풀 수 없습니다.)