# 9489_고대유적
# 2022-08-12

import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    N, M = map(int, input().split())
    relic_map = []
    for _ in range(N):
        relic_map.append(list(map(int, input().split())))
    ver_max = hor_max = result = 0
    for i in range(N):
        for j in range(M):
            if relic_map[i][j] == 1:
                hor_max += 1
            elif relic_map[i][j] == 0:
                hor_max = 0
            if hor_max > result :
                result = hor_max
        hor_max = 0
    hor_max = 0
    for i in range(M):
        for j in range(N):
            if relic_map[j][i] == 1:
                hor_max += 1
            elif relic_map[j][i] == 0:
                hor_max = 0
            if hor_max > result :
                result = hor_max
        hor_max = 0
    print('#{} {}' .format(t, result))