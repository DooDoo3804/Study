# 5097_회전
# 2022-08-25
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, 1+T):
    N, M = map(int, input().split())
    num_list = list(map(int, input().split()))
    remain = M % N
    print('#{} {}' .format(t, num_list[remain]))