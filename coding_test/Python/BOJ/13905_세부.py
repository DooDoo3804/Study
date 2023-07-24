import sys
n, m = map(int, sys.stdin.readline().strip().split())
s, e = map(int, sys.stdin.readline().strip().split())
nodes = []
for _ in range(m):
    a, b, w = map(int, sys.stdin.readline().strip().split())
    nodes.append([a, b, w])
visited = [0 for _ in range(n+1)]
nodes.sort(key=lambda x : x[2], reverse=True)
mst = [[] for _ in range(n+1)]


def find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]


def check_connect(x, y):
    x = find(x)
    y = find(y)
    if x < y:
        parent[y] = x
    elif x > y:
        parent[x] = y


parent = [i for i in range(n + 1)]
for node in nodes:
    a, b, w = node[0], node[1], node[2]
    if find(a) != find(b):
        check_connect(a, b)
        mst[a].append([b, w])
        mst[b].append([a, w])

stack = []
stack.append((s, 1000000))
visited[s] = 1
result = 0

while stack:
    node, value = stack.pop(0)
    if node == e:
        result = value
        break
    for a, w in mst[node]:
        if not visited[a]:
            sub_value = min(value, w)
            stack.append((a, sub_value))
            visited[a] = 1
print(result)