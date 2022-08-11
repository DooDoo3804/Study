# 4837_부분집합의_합
# 2022-08-11
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    N, K = map(int, input().split())
    result = 0
    group_list = []
    for i in range(1 << 12):
        small_group_list = []
        for j in range(12):
            if i & (1 << j):
                small_group_list.append(j+1)
        group_list.append(small_group_list)
    for group in group_list:
        count = 0
        group_sum = 0
        for _ in group:
            count += 1
        if count == N :
            for i in group:
                group_sum += i
        if group_sum == K :
            result += 1
    print('#{} {}'.format(t, result))