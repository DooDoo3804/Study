# 10163_색종이(BOJ)
# 2022-08-28
import sys
sys.stdin = open('input.txt', 'r')

N = int(input())
grid = [[0 for _ in range(1001)]for _ in range(1001)]
for n in range(1, 1+N):
    sx, sy, w, h = map(int, input().split())
    for y in range(sy, sy+h):
        for x in range(sx, sx+w):
            grid[1000-y][x] = n
for n in range(1, 1+N):
    result = 0
    for line in grid:
        result += line.count(n)
    print(result)