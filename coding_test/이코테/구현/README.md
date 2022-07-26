### 구현

---

- 문법을 정확하게 알아야 함
- __완전탐색__ : 모든 경우의 수를 다 계산하는 해결 방법
- __시뮬레이션__ : 문제에서 제시한 알고리즘을 한 단계씩 차례대로 직접 수행

- 메모리 제한

  | 데이터의 개수(리스트의 길이) | 메모리 사용량 |
  | ---------------------------- | ------------- |
  | 1000                         | 약 4KB        |
  | 1000000                      | 약 4MB        |
  | 10000000                     | 약 40MB       |

- 보통 문제가 길다



1. 상하좌우
   - N X N 크기의 정사각형 공간(가장 왼쪽위가 (1, 1))
   - 계획서 L좌 / R우 / U상 / D하
   - 첫째 줄 공간의 크기 N
   - A의 이동 계획서 (칸을 벗어나면 그 행동 무시)

```python
n = int(input())
plans = input().split()
x, y = 1, 1
move_list = ['U', 'D', 'L', 'R']
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for plan in plans:
    for i in range(len(move_list)):
        if plan == move_list[i]:
            nx = x + dx[i]
            ny = y + dy[i]
    if nx < 1 or ny < 1 or nx > n or ny > n:
        continue
    x, y = nx, ny
print(x, y)
```

2. 시각
   - 첫째 줄에 N이 입력
   - 0시부터 N시 59분 59초 까지 하나라도 3이 포함되는 모든 경우의 수 합하기

```python
n = int(input())
count = 0
for i in range(n+1) :
    for j in range(60):
        for k in range(60):
            if '3' in str(i) + str(j) + str(k):
                count += 1
print(count)
```

3. 왕실의 나이트
   - 8  X 8좌표
   - 나이트는 L자 형태로만 이동

```python
start_loc = input()
row = int(start_loc[1])
column = int(ord((start_loc[0]))) - int(ord('a')) + 1

steps = [(-2, -1), (-2, 1), (2, -1), (2, 1), (1, 2), (-1, 2), (1, -2), (-1, -2)]
result = 0
for step in steps:
    next_row = row + step[0]
    next_column = column + step[1]
    if next_row >= 1 and next_row <=8 and next_column >= 1 and next_column <=8:
        result += 1

print(result)
```

4. 게임 개발
   - N X M 크기의 직사각형
   - 현재 위치에서 방향을 왼쪽방향으로 부터 갈 곳을 정함
   - 바로 왼쪽에 가보지 않은 칸이 존재한다면 왼쪽으로 횐전한 다음 왼쪽으로 한칸 전진
   - 가본 칸이라면 돌기만 한다
   - 모두 가본 칸이라면 바라보는 방향을 유지한 채 한칸 뒤로 가고 탐색 반복
   - 첫째 줄에 N M
   - 둘째줄에 (A, B) 방향 d
   - 0 북쪽 / 1 동쪽 / 2 남쪽 / 3 서쪽
   - 1 바다 / 0 육지
