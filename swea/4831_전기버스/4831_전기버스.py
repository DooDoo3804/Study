# 4831_전기버스
# 2022-08-09
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, T+1):
    K, N, M = map(int, input().split())
    stop_list = [0]
    stop_list.extend(list(map(int, input().split())))
    stop_list.append(N)
    start = 0
    count = 0
    while start < N:
        start += K
        for i in range(0, M+1):
            if stop_list[i] <= start < stop_list[i+1]:
                count += 1
                start = stop_list[i]
            elif stop_list[-1] < start < N:
                count += 1
                break
            elif stop_list[i]-stop_list[i-1] > K:
                count = 0
                start = 0
                break
        if start == 0 :
            break
    print('#{} {}'.format(t, count))
