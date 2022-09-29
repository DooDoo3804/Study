# 5249_최소_신장_트리
# 2022-09-29
import sys
sys.stdin = open('input.txt', 'r')

def find_set(x):
    while x != rep[x]:
        x = rep[x]
    return x

def union(x,y):
    rep[find_set(y)] = find_set(x)

T = int(input())
for t in range(1, 1 + T):
    n, E = map(int, input().split())
    nodes = []
    for _ in range(E):
        nodes.append(list(map(int, input().split())))
    nodes.sort(key=lambda x:x[2])
    rep = [i for i in range(E+1)]
    N = E+1
    cnt = 0
    total = 0
    for u, v, w in nodes:
        if find_set(u) != find_set(v):
            cnt += 1
            union(u, v)
            total += w
            if cnt == N-1:
                break
    print('#{} {}' .format(t, total))

