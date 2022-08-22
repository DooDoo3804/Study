### 그리디

---

- 단순
- 강력

- 외우지 않아도 문제에 바로 적용 가능
- 문제풀이를 위한 쵯소한의 아이디어를 떠올리고 이것이 정당한지 검토할 수 있어야 함



1. 거스름돈 문제
   - 거스름돈 500원, 100원, 50원, 10원

```python
# 보통 for 문올 통해 큰 거스름돈 부터 처리한다
# 화폐의 종류가 K개 이면 복잡도는 O(K)
# 화폐가 무작위로 주어지면 그리디 알고리즘으로 해결할 수 없다
```

2. 큰 수의 법칙
   - N, M, K
   - N개의 자연수 배열 (공백 구분) / K <= M / N개의 수들을 총M번 더해서 가장 큰 수 만들기(최대 K번 넘게 연속할 수 없다)

```python
n, m, k = map(int, input().split())
n_data = list(input().split())
n_data.sort()
num1 = int(n_data[-1])
num2 = int(n_data[-2])
max_list = 0
max_list += (m // (k+1)) * (num1*k + num2)
max_list += (m % (k+1)) * num1
print(max_list)
```

3. 숫자 카드 게임
   - 여러 개의 숫자 카드 중에서 가장 높은 숫자가 쓰인 카드 한 장을 뽑는 게임
   - N X M 카드
   - 먼저 뽑고자 하는 행 선택 / 그 중 가장 작은 카드 셀렉 / 최종적으로 가장 높은 숫자의 카드를 뽑을 수 있는 전략
   - 첫 째줄에 N X M 입력 / 그 다음부터 숫자 카드 배열

```python
n, m = map(int, input().split())
minimum_list = []
for i in range(n):
    num_list = list(input().split())
    minimum_list.append(min(num_list))
print(max(minimum_list))
# 이중 반복문 구조로도 가능
```

4. 1이 될 때까지
   - N이 K로 나눠지면 나눈다
   - 아니면 N에서 1을 뺀다
   - 첫 째줄에 N K 입력 / 1이 출력되는 횟수의 최솟값

```python
n, k = map(int, input().split())
count = 0
while True :
    if n == 1 :
        break
    elif n % k == 0 :
        n = n/k
        count += 1
    else :
        n = n-1
        count += 1
```

