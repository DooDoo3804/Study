# 1966_숫자를 정렬하자
# 2022-08-11

import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, T+1):
    N = int(input())
    num_list = list(map(int, input().split()))
    for i in range(N):
        for j in range(0, i):
            if num_list[j] > num_list[i]:
                num_list[i], num_list[j] = num_list[j], num_list[i]
    print('#{}' .format(t), *num_list)