import sys
n, m = map(int, sys.stdin.readline().split())
node = [[] for _ in range(n+1)]
node_m = []
for _ in range(n-1):
    a, b, d = map(int, sys.stdin.readline().split())
    node[a].append([b, d])
    node[b].append([a, d])
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    node_m.append([a, b])


def find_d(n, d):
    global count, done
    visited[n] = 1
    for i in node[n]:
        if i[0] == d:
            count += i[1]
            done = 1
            return
        elif visited[i[0]] == 0:
            count += i[1]
            find_d(i[0], d)
            if done:
                return
            else:
                count -= i[1]
                visited[i[0]] = 0


for j in node_m:
    count, done = 0, 0
    visited = [0 for _ in range(n + 1)]
    find_d(j[0], j[1])
    print(count)
