# 1265_달란트
# 2022-09-13
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    n, p = map(int, input().split())
    a = n // p
    b = n % p
    result = a**(p-b) * (a+1)**b
    print('#{} {}' .format(t, result))