# 5186_이진수2
# 2022-09-20
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, 1+T):
    result = ''
    sub_sum = 0
    N = float(input())
    cnt = -1
    while sub_sum != N:
        if sub_sum+(2**cnt) <= N:
            sub_sum += 2**cnt
            result += '1'
        else:
            result += '0'
        cnt -= 1
        if cnt < -13:
            result = 'overflow'
            break
    print('#{} {}' .format(t,result))