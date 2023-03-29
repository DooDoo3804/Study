import sys
sys.setrecursionlimit(100000)
n, r, q = map(int, sys.stdin.readline().split())


def tree(c, p):
    for node in nodes[c]:
        if node != p:
            parent[node] = c
            child[c].append(node)
            tree(node, c)


def count_child(p):
    size[p] = 1
    for c in child[p]:
        count_child(c)
        size[p] += size[c]


parent = [0 for _ in range(n+1)]
child = [[] for _ in range(n+1)]
nodes = [[] for _ in range(n+1)]
size = [0 for _ in range(n+1)]
for _ in range(n-1):
    i, j = map(int, sys.stdin.readline().split())
    nodes[i].append(j)
    nodes[j].append(i)
tree(r, -1)
count_child(r)
answer = []
for _ in range(q):
    answer.append(size[int(input())])
for a in answer:
    print(a)