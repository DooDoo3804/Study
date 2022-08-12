# 9367_점점_커지는_당근의_개수
# 2022-08-12

import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, T+1):
    N = int(input())
    carrot_list = list(map(int, input().split()))
    pre_crt = nxt_crt = carrot_count = result = 0
    for n in range(N):
        nxt_crt = carrot_list[n]
        if pre_crt < nxt_crt :
            carrot_count += 1
            if carrot_count > result:
                result = carrot_count
        else :
            carrot_count = 1
        pre_crt = nxt_crt
    print('#{} {}' .format(t, result))