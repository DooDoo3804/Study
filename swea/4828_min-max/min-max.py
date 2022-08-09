# 4828_min-max
# 2022-08-09
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, T+1):
    n = int(input())
    numbers_list = list(map(int, input().split()))
    for i in range(0, n):
        for j in range(0, i):
            if numbers_list[j] > numbers_list[i]:
                numbers_list[j], numbers_list[i] = numbers_list[i], numbers_list[j]
    print('#{} {}' .format(t, numbers_list[-1]-numbers_list[0]))