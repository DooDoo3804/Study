import sys
array_map = []
n, m = map(int, sys.stdin.readline().split())
for _ in range(n):
    array_map.append(list(map(int, sys.stdin.readline().split())))
check_d = [[0, 1], [0, -1], [1, 0], [-1, 0]]
group_map = [[0 for _ in range(m)] for _ in range(n)]
group_num = 1
g_count = [0]
result = 0


def check_group(i, j):
    global count
    for d in check_d:
        next_i, next_j = i + d[0], j + d[1]
        if 0 <= next_i < n and 0 <= next_j < m and not group_map[next_i][next_j] and array_map[next_i][next_j]:
            sub_queue.append([next_i, next_j])
            group_map[next_i][next_j] = group_num
            count += 1
    sub_queue.pop(0)


for i in range(n):
    for j in range(m):
        if array_map[i][j] == 1 and not group_map[i][j]:
            count = 1
            group_map[i][j] = group_num
            sub_queue = [[i, j]]
            while sub_queue:
                check_group(sub_queue[0][0], sub_queue[0][1])
            g_count.append(count)
            group_num += 1


for i in range(n):
    for j in range(m):
        if array_map[i][j] == 0:
            count = 1
            visited = []
            for d in check_d:
                next_i, next_j = i+d[0], j+d[1]
                if 0 <= next_i < n and 0 <= next_j < m and array_map[next_i][next_j] == 1 and group_map[next_i][next_j] not in visited:
                    count += g_count[group_map[next_i][next_j]]
                    visited.append(group_map[next_i][next_j])
            result = max(result, count)
print(result)