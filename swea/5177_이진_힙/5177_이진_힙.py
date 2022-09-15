# 5177_이진_힙
# 2022-09-15

import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    N = int(input())
    num_list = list(map(int, input().split()))
    stack = [0] * (N+1)
    for i, v in enumerate(num_list):
        stack[i+1] = v
        while stack[(i+1)//2] > v:
            stack[(i + 1) // 2], stack[i+1] = stack[i+1], stack[(i + 1) // 2]
            i = (i+1) // 2 -1
    result = 0
    idx = N
    while True:
        idx = idx // 2
        if idx == 0:
            break
        result += stack[idx]
    print('#{} {}' .format(t, result))