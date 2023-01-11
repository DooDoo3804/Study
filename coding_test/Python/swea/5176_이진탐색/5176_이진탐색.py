# 5176_이진탐색
# 2022-09-15

import sys
sys.stdin = open('input.txt', 'r')

def fill_tree(i):
    global idx
    if par[i]:
        fill_tree(ch1[i])
        heap[i] = idx
        idx += 1
        fill_tree(ch2[i])


T = int(input())
for t in range(1, T+1):
    N = int(input())
    heap = [0] * (N+1)
    par = [0] * (N+1)
    ch1 = [0] * (N+1)
    ch2 = [0] * (N+1)
    for i in range(1, N+1) :
        par[i] = i
        if i * 2 < N + 1:
            ch1[i] = i*2
        if i*2+1 < N+1:
            ch2[i] = i*2+1
    idx = 1
    fill_tree(1)
    print('#{} {} {}'.format(t, heap[1], heap[N//2]))
