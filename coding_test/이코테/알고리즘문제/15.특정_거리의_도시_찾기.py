from collections import deque
N, M, K, X = map(int, input().split())
nodes = [[] for _ in range(N+1)]
for _ in range(M):
    i, j = map(int, input().split())
    nodes[i].append(j)
distance = [-1] * (N+1)
distance[X] = 0
num_stack = deque([X])
stack = [0] * (N+1)
visited = [0] * N
while num_stack:
    now = num_stack.popleft()
    for node in nodes[now]:
        if distance[node] == -1:
            distance[node] = distance[now] + 1
            num_stack.append(node)
flag = True
for i, v in enumerate(distance):
    if v == K:
        flag = False
        print(i)
if flag:
    print(-1)
