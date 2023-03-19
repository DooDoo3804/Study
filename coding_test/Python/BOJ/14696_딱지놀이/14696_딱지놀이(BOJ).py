# 14696_딱지놀이(BOJ)
# 2022-08-28
import sys
sys.stdin = open('input.txt', 'r')

# 별 4 동그라미 3 네모 2 세모 1
N = int(input())
for _ in range(N):
    a_list = list(map(int, input().split()))
    b_list = list(map(int, input().split()))
    a_list.pop(0)
    b_list.pop(0)
    a_count = b_count = 0
    for i in range(4, 0, -1):
        a_count = a_list.count(i)
        b_count = b_list.count(i)
        if a_count == b_count:
            result = 'D'
            continue
        elif a_count < b_count:
            print('B')
            result = 0
            break
        elif a_count > b_count:
            print('A')
            result = 0
            break
    if result == 'D':
        print('D')
