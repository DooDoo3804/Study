# 4839_이진탐색
# 2022-08-11
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
def search_num(P, A):
    l = 1
    r = P
    count = 0
    while l <= r :
        c = int((l+r)/2)
        count += 1
        if c == A :
            return count
        elif c > A :
            r = c
        else :
            l = c

for t in range(1, T+1):
    P, A, B = map(int, input().split())
    winner = 0
    a_count = search_num(P, A)
    b_count = search_num(P, B)

    if a_count < b_count:
        winner = 'A'
    elif a_count == b_count:
        winner = 0
    elif a_count > b_count:
        winner = 'B'

    print('#{} {}' .format(t, winner))