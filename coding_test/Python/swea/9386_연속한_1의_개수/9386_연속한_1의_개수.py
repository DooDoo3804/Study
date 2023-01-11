# 9386_연속한_1의_개수
# 2022-08-12

import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    num_len = int(input())
    num_list = list(str(input()))
    count = 0
    count_s = 0
    for idx in range(num_len):
        if num_list[idx] == '1':
            count_s += 1
            if count_s > count:
                count = count_s
        else : count_s = 0
    print('#{} {}' .format(t, count))