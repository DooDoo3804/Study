import sys
sys.stdin = open('input.txt', 'r')
N, K = map(int, input().split())
boys = []
girls = []
for _ in range(N):
    s, g = map(int, input().split())
    if s == 1:
        boys.append(g)
    elif s == 0:
        girls.append(g)
result = 0
for i in range(1, 7):
    if boys.count(i) % K:
        result += boys.count(i)//K+1
    elif boys.count(i) % K == 0:
        result += boys.count(i) // K
    if girls.count(i) % K:
        result += girls.count(i) // K + 1
    elif girls.count(i) % K == 0:
        result += girls.count(i) // K
print(result)