# 1206_view
# 220808

# 아래에 정답 코드 작성
# 내장 모듈은 사용 가능

import sys
sys.stdin = open('input.txt', 'r')

# 함수를 만드는 경우 여기에 작성

# T = int(input())
for tc in range(1, 10+1):
    n = int(input())
    T = list(map(int, input().split()))
    check = [-2, -1, 1, 2]
    count = 0
    for i in range(2, n-2):
        result = T[i]
        for checkidx in check:
            if 0 <= (T[i] - T[i+checkidx]) <= result:
                result = T[i] - T[i+checkidx]
            elif T[i] - T[i+checkidx] == 0:
                continue
            elif T[i] - T[i+checkidx] < 0 :
                result = 0
                continue
        count += result
    print('#{} {}' .format(tc, count))
