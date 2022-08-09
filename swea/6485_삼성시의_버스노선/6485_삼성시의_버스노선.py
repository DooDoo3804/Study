# 6485-삼성시의_버스노선
# 2022-08-09
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    N = int(input())
    case_list = []

    for _ in range(N):
        case_list.append(list(map(int, input().split())))
    P = int(input())
    result = [0] * P
    for p in range(1, P+1):
        stop = int(input())
        for case in case_list:
            if stop in range(case[0], case[1]+1):
                result[p-1] += 1
    print('#{}' .format(t), *result)