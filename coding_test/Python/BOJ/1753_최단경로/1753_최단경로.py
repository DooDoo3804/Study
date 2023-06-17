import sys
import heapq
INF = 2134567890
v, e = map(int, sys.stdin.readline().strip().split())
k = int(sys.stdin.readline().strip())
nodes = [[] for _ in range(v + 1)]
d = [INF for _ in range(v + 1)]

for _ in range(e):
    u, v, w = map(int, sys.stdin.readline().strip().split())
    nodes[u].append([w, u, v])

d[k] = 0
pq = []
heapq.heappush(pq, (0, k, k))
while pq:
    now_node = heapq.heappop(pq)
    for next_node in nodes[now_node[2]]:
        n_weight = now_node[0] + next_node[0]
        if n_weight < d[next_node[2]]:
            d[next_node[2]] = n_weight
            heapq.heappush(pq, (n_weight, next_node[1], next_node[2]))

for i, value in enumerate(d):
    if i == 0:
        continue
    if value == 2134567890:
        print("INF", end="\n")
    else:
        print(value)