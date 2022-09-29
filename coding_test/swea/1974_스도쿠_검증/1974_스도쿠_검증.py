# 1974_스도쿠_검증
# 2022-08-16
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    sudoku_list = []
    for _ in range(9):
        sudoku_list.append(list(map(int, input().split())))
    result = 1
    # 가로검증
    for i in range(9):
        num_check = [0] * 9
        for j in range(9):
            num_check[sudoku_list[i][j]-1] += 1
        if 0 in num_check:
            result = 0
            break
    # 세로검증
    for i in range(9):
        num_check = [0] * 9
        for j in range(9):
            num_check[sudoku_list[j][i]-1] += 1
        if 0 in num_check:
            result = 0
            break
    # 사각형 검증
    for i in [0, 3, 6]:
        for j in [0, 3, 6]:
            num_check = [0] * 9
            for k in range(3):
                for l in range(3):
                    num_check[sudoku_list[i+k][j+l]-1] += 1
            if 0 in num_check:
                result = 0
                break
    print('#{} {}'. format(t, result))