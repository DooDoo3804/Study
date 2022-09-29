# 4836_색칠하기
# 2022-08-11
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    N = int(input())
    grid = [[0] * 10 for _ in range(10)]
    count = 0
    # y,x
    for _ in range(N):
        r1, c1, r2, c2, color = map(int, input().split())
        area = (r2-r1)*(c2-c1)
        for i in range(c1, c2+1) :
            for j in range(r1, r2+1):
                if color == 1 and (grid[i][j] == 0 or grid[i][j] == 2):
                    grid[i][j] += 1
                elif color == 2 and (grid[i][j] == 0 or grid[i][j] == 1):
                    grid[i][j] += 2
    for i in range(10):
        for j in range(10):
            if grid[i][j] == 3:
                count += 1
    print('#{} {}' .format(t, count))