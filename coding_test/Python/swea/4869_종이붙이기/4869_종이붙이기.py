# 4869_종이붙이기
# 2022-08-18

import sys
sys.stdin = open('input.txt', 'r')
T = int(input())

def fac(num):
    if num == 0:
        return 1
    else :
        return num * fac(num-1)
for t in range(1, T+1):
    N = int(input())
    n = N // 10
    paper_list = []
    n_2 = 0
    result = 0

    while n_2 * 2 <= n:
        n_1 = 0
        in_list = []
        in_list.append(n_2)
        count = 2 * n_2
        while count < n :
            n_1 += 1
            count += 1
        in_list.append(n_1)
        paper_list.append(in_list)
        n_2 += 1

    for paper in paper_list:
        num_2 = paper[0]
        num_1 = paper[1]
        if num_2 :
            result += ((fac(num_1 + num_2)) / (fac(num_1) * fac(num_2))) * (2**num_2)
        else :
            result += (fac(num_1 + num_2)) / (fac(num_1) * fac(num_2))
    print('#{} {}' .format(t, int(result)))