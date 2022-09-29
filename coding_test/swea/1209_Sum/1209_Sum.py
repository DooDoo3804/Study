# 1209_Sum
# 2022-08-09
import sys
sys.stdin = open('input.txt', 'r')

for t in range(1, 11):
    max_sum = 0
    t = int(input())
    num_list = []
    for _ in range(100):
        num_list.append(list(map(int, input().split())))
    for i in range(100):
        sum_hor = sum_ver = 0
        for j in range(100):
            sum_hor += num_list[i][j]
            sum_ver += num_list[j][i]
        if sum_hor > sum_ver and sum_hor > max_sum:
            max_sum = sum_hor
        elif sum_ver > sum_hor and sum_ver > max_sum:
            max_sum = sum_ver
    sum_crs = 0
    for i in range(100):
        for j in range(100):
            if i == j:
                sum_crs += num_list[i][j]
                break
    if max_sum < sum_crs:
        max_sum = sum_crs
    sum_crs = 0
    for i in range(100):
        for j in range(100):
            if (i+j) == 99:
                sum_crs += num_list[i][j]
                break
    if max_sum < sum_crs:
        max_sum = sum_crs
    print('#{} {}' .format(t, max_sum))
