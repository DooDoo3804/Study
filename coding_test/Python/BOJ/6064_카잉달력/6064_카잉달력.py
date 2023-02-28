def max_g(a, b):
    while b:
        a, b = b, a%b
    return a


def min_g(a, b):
    return a*b / max_g(a,b)


import sys
input = sys.stdin.readline
n = int(input())
for _ in range(n):
    m, n, x, y = map(int, input().split())
    start = x
    answer = -1
    while start <= min_g(m, n):
        if (start-y)%n == 0:
            answer = start
            break
        start += m
    print(answer)