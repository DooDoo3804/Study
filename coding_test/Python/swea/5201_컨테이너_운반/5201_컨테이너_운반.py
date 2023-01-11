# 5201_컨테이너_운반
# 2022-09-22

import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, 1+T):
    n, m = map(int, input().split())
    weights = sorted(list(map(int, input().split())))
    trucks = sorted(list(map(int, input().split())))
    result = 0
    while trucks:
        if weights == []:
            break

        if trucks[-1] >= weights[-1]:
            trucks.pop()
            result += weights[-1]
            weights.pop()
        elif trucks[-1] < weights[-1]:
            weights.pop()
    print('#{} {}' .format(t, result))