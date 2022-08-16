# 4861_회문
# 2022-08-16

import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    N, M = map(int, input().split())
    str_list = []

    for _ in range(N):
        str_list.append(list(map(str, input())))

    target_hrz_row = target_hrz_col = target_ver_row = target_ver_col = 0
    for i in range(N):
        for n in range(N-M+1):
            for m in range(int(M/2)):
                if str_list[i][n+m] == str_list[i][n+M-1-m]:
                    count += 1
                else :
                    count = 0
                    break
            if count == int(M/2) :
                target_hrz_col = n
                target_hrz_row = i
                hrz = True

    for i in range(N):
        for n in range(N-M+1):
            for m in range(int(M/2)):
                if str_list[n+m][i] == str_list[n+M-1-m][i]:
                    count += 1
                else :
                    count = 0
                    break
            if count == int(M/2) :
                target_ver_col = i
                target_ver_row = n
                hrz = False
    if hrz :
        print('#{} ' .format(t), end='')
        for m in range(M):
            print(str_list[target_hrz_row][target_hrz_col+m], end='')
        print()
    else :
        print('#{} ' .format(t), end='')
        for m in range(M):
            print(str_list[target_ver_row+m][target_ver_col], end='')
        print()