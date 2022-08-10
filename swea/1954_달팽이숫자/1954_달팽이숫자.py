# 1954_달팽이숫자
# 2022-08-10
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
# 우하좌상
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
direction = 0

def change_direction(direction):
    direction += 1
    if direction > 3:
        direction = 0
    return direction

for t in range(1, T+1):
    pre_loc = [0, 0]
    direction = 0
    N = int(input())
    result = [[0]*N for _ in range(N)]
    max_num = N**2
    # 결과값
    moved = [[0]*N for _ in range(N)]
    # 움직임 확인
    for i in range(1, max_num+1):
        if i == 1:
            result[0][0] = 1
            moved[0][0] = 1
            continue
        x = pre_loc[1] + dx[direction]
        y = pre_loc[0] + dy[direction]
        if 0 > x or x >= N or 0 > y or y >= N or moved[y][x] == 1:
            direction = change_direction(direction)
            x = pre_loc[1] + dx[direction]
            y = pre_loc[0] + dy[direction]
        pre_loc[0] = y
        pre_loc[1] = x
        moved[pre_loc[0]][pre_loc[1]] = 1
        result[pre_loc[0]][pre_loc[1]] = i
    print('#{}'.format(t))
    for i in range(N):
        for j in range(N):
            print(result[i][j], end=' ')
        print()