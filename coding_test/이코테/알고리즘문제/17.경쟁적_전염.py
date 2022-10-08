n, m = map(int, input().split())
total_map = [[] for _ in range(n)]
for j in range(n):
    total_map[j] = list(map(int, input().split()))
s, x, y = map(int, input().split())
max_num = 0
for j in range(n):
    for i in range(n):
        if total_map[j][i] > max_num :
            max_num = total_map[j][i]
t = 0
directions = [[0,1], [1,0], [0,-1], [-1,0]]
while t != s:
    t += 1
    c = 1
    visited = [[0 for _ in range(n)] for _ in range(n)]
    while c != max_num+1:
        for j in range(n):
            for i in range(n):
                if total_map[j][i] == c and visited[j][i] == 0:
                    visited[j][i] = 1
                    for direction in directions:
                        n_i = i + direction[1]
                        n_j = j + direction[0]
                        if 0 <= n_i < n and 0 <= n_j <n and total_map[n_j][n_i] == 0 and visited[n_j][n_i] == 0:
                            visited[n_j][n_i] = 1
                            total_map[n_j][n_i] = c
        c += 1
print(total_map[x-1][y-1])