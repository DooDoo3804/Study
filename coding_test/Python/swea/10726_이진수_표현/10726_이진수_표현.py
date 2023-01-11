# 10726_이진수_표현
# 2022-09-20
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, 1+T):
    N, M = map(int,input().split())
    binary = ''
    for j in range(31, -1, -1):
        binary += '1' if M & (1 << j) else '0'
    result = 'ON'
    for i in range(1, N+1):
        if binary[-i] == '0':
            result = 'OFF'
    print('#{} {}' .format(t, result))