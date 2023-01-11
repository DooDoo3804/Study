# 4835_구간합
# 2022-08-09
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, T+1):
    N, M = map(int, input().split())
    numbers = list(map(int, input().split()))
    num_list = [0] * (N-M+1)
    for i in range(N-M+1):
        sum_num = 0
        for j in range(0, M):
            sum_num += numbers[i+j]
        num_list[i] = sum_num
    for i in range(1, N-M+1):
        for j in range(0, i):
            if num_list[j] > num_list[i]:
                num_list[i], num_list[j] = num_list[j], num_list[i]
    result = num_list[-1] - num_list[0]
    print('#{} {}' .format(t, result))