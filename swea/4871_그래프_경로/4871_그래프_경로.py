# 4871_그래프_경로
# 2022-08-18
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())

for t in range(1, T+1):
    V, E = map(int, input().split())
    nodes = [[] for _ in range(V)]
    visited = [0 for _ in range(V)]
    for e in range(E):
        start, end = map(int, input().split())
        nodes[start-1].append(end)
    S, G = map(int, input().split())
    v = S
    move = [S]
    visited[v-1] = 1
    result = 0
    while True:
        if nodes[v-1] == []:
            move.pop()
            if move == []:
                result = 0
                break
            v = move[-1]
        elif visited[nodes[v-1][-1]-1] == 0:
            v = nodes[v-1][-1]
            visited[v-1] = 1
            move.append(v)
        else :
            # visited[nodes[v - 1][-1] - 1] == 1
            nodes[v-1].pop()
            v = move[-1]
        if move == []:
            result = 0
            break
        if v == G :
            result = 1
            break
    print('#{} {}' .format(t, result))