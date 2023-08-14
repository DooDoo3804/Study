import sys
r, c, n = map(int, sys.stdin.readline().split())
total_map = []
count_map = [[0 for _ in range(c)] for _ in range(r)]
cross = [[0,0], [0,1], [0,-1], [1,0], [-1,0]]
delete_check = [[0 for _ in range(c)] for _ in range(r)]
for _ in range(r):
    total_map.append(list(str(sys.stdin.readline().rstrip())))
timer = 0
for i in range(r):
    for j in range(c):
        if total_map[i][j] == 'O':
            count_map[i][j] = 3
while timer != n:
    timer += 1
    # 타이머 감소
    for i in range(r):
        for j in range(c):
            count_map[i][j] -= 1
    # 처음 1초라면 무시
    if timer == 1:
        continue
    # 아니면 아래 진행
    else:
        for i in range(r):
            for j in range(c):
                if total_map[i][j] == '.':
                    total_map[i][j] = 'O'
                    count_map[i][j] = 3
                if count_map[i][j] == 0 and total_map[i][j] == 'O':
                    for c_select in cross:
                        near_x = j + c_select[1]
                        near_y = i + c_select[0]
                        if 0 <= near_x < c and 0 <= near_y < r:
                            delete_check[near_y][near_x] = -1
        for i in range(r):
            for j in range(c):
                if delete_check[i][j] == -1:
                    total_map[i][j] = '.'
                    delete_check[i][j] = 0
for i in range(r):
    for j in range(c):
        print(total_map[i][j], end="")
    print()