# 5688_세제곱근을_찾아라
# 2022-09-16

import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, 1+T):
    N = int(input())
    cnt = 0
    while cnt**3 < N:
        cnt += 1
        n = cnt**3
        if n == N:
            result = cnt
            break
        else:
            result = -1
    print('#{} {}' .format(t, result))