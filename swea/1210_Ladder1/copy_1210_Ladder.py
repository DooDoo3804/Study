# 1210_Ladder
# 2022-08-11
import sys
sys.stdin = open('input.txt', 'r')
for _ in range(1, 11):
    t = int(input())
    pre_direction = -1
    # 0우 1좌
    start = 0
    pre_loc = [99, 0]
    total_map = [list(map(int, input().split())) for _ in range(100)]
    # 끝점 찾기
    for i in range(100):
        if total_map[99][i] == 2:
            pre_loc[1] = i
    while start == 0:
        if pre_loc[1] != 99 and pre_direction != 1 and total_map[pre_loc[0]][pre_loc[1]+1] == 1:
            pre_loc[1] += 1
            pre_direction = 0
        elif pre_loc[0] != 0 and pre_direction != 0 and total_map[pre_loc[0]][pre_loc[1]-1] == 1:
            pre_loc[1] -= 1
            pre_direction = 1
        else :
            pre_loc[0] -= 1
            pre_direction = -1
        if pre_loc[0] == 0 :
            start = pre_loc[1]
    print('#{} {}' .format(t, start))
