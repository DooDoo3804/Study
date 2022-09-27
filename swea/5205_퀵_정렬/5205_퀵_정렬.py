# 5205_퀵_정렬
# 2022-09-27
import sys
sys.stdin = open('input.txt', 'r')

def partition(l, r):
    pivot = num_list[l]
    i = l
    j = r
    while i <= j:
        while i <= j and num_list[i] <= pivot:
            i += 1
        while i <= j and num_list[j] >= pivot:
            j -= 1
        if i < j:
            num_list[i], num_list[j] = num_list[j], num_list[i]
    num_list[l], num_list[j] = num_list[j], num_list[l]
    return j

def q_sort(l, r):
    if l < r:
        s = partition(l, r)
        q_sort(l, s-1)
        q_sort(s+1, r)

T = int(input())
for t in range(1, 1+T):
    n = int(input())
    num_list = list(map(int, input().split()))
    q_sort(0, n-1)
    print('#{} {}' .format(t, num_list[n//2]))

