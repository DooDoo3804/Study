# 1249_보급로
# 2022-09-27

import sys
sys.stdin = open('input.txt', 'r')

def find_min(now, sub_sum):
    global result
    if now == [n-1,n-1]:
        if result > sub_sum:
            result = sub_sum
            return
    for direction in directions:
        di = now[1] + direction[1]
        dj = now[0] + direction[0]
        if 0 <= di < n and 0 <= dj < n and visited[dj][di] and sub_sum+total_map[dj][di] < result :
            visited[dj][di] = 1
            sub_sum += total_map[dj][di]
            find_min([dj, di], sub_sum)
            visited[dj][di] = 0
            sub_sum -= total_map[dj][di]

T = int(input())
for t in range(1, 1+T):
    n = int(input())
    total_map = [[] for _ in range(n)]
    visited = [[0 for _ in range(n)] for _ in range(n)]
    visited[0][0] = 1
    now = [0, 0]
    for i in range(n):
        total_map[i] = list(input())
    directions = [[0, 1], [1, 0], [-1, 0], [0, -1],]
    sub_sum = 0
    result = 0

    for i in range(n):
        result += int(total_map[0][i])
    for i in range(1, n):
        result += int(total_map[i][n-1])
    find_min(now, sub_sum)
    print(result)
