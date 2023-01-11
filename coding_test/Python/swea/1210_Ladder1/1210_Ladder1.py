import sys
sys.stdin = open('input.txt', 'r')
# 좌우하
for _ in range(1, 11):
    start = 0
    total_map = []
    t = int(input())
    for _ in range(100):
        total_map.append(list(map(int, input().split())))
    for i in range(100):
        pre_loc = [0, 0]
        if total_map[0][i] == 1:
            pre_loc[1] = i
            move_map = [[0]*100 for _ in range(100)]
            move_map[0][i] = 1
        while True :
            if pre_loc[1] != 99 and total_map[pre_loc[0]][pre_loc[1]+1] == 1 and move_map[pre_loc[0]][pre_loc[1]+1] != 1:
                pre_loc[1] += 1
                move_map[pre_loc[0]][pre_loc[1]] = 1
            elif pre_loc[1] != 0 and total_map[pre_loc[0]][pre_loc[1]-1] == 1 and move_map[pre_loc[0]][pre_loc[1]-1] != 1:
                pre_loc[1] -= 1
                move_map[pre_loc[0]][pre_loc[1]] = 1
            elif pre_loc[0] == 99:
                break
            elif total_map[pre_loc[0]+1][pre_loc[1]] == 1:
                pre_loc[0] += 1
                move_map[pre_loc[0]][pre_loc[1]] = 1
            elif total_map[pre_loc[0]+1][pre_loc[1]] == 2:
                start = i
                break
    print('#{} {}' .format(t, start))
