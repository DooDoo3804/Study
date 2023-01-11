# 5251_최소_이동_거리
# 2022-09-29
import sys
sys.stdin = open('input.txt', 'r')

def dij(N, X, adj, d):
    for i in range(1+N):
        d[i]= adj[X][i]
    U = [X]
    for _ in range(N-1):
        w = -1
        for i in range(1, 1+N):
            if (i not in U) and d[i] < d[w]:
                w = i
        U.append(w)
        for v in range(1, N+1):
            if 0 < adj[w][v] < 100000:
                d[v] = min(d[v], d[w] + adj[w][v])




T = int(input())
for t in range(1, 1+T):
    N, M = map(int, input().split())
    adj1 = [[1000000] * (N+1) for _ in range(N+1)]
    for i in range(1+N):
        adj1[i][i] = 0
    for _ in range(M):
        x, y, c = map(int, input().split())
        adj1[x][y] = c
    dout = [0] * (1+N)
    dij(N, 0, adj1, dout)
    print('#{} {}' .format(t, dout[-1]))