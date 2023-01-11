# 13994_새로운_버스_노선
# 2022-08-12
import sys
sys.stdin = open('sample.txt', 'r')
T = int(input())
for t in range(1, T+1):
    N = int(input())
    bus_stop = [0] * 1000
    for n in range(N):
        bus_type, A, B = map(int, input().split())
        #1 일반 모든 정류장
        # 2 급행 A가 짝수면 짝수 홀수면 홀수
        # 3 광역급행 A가 짝수면 4의배수 홀수면 3의 배수 not 10의 배수
        if bus_type == 1:
            for i in range(A, B+1):
                bus_stop[i-1] += 1
        elif bus_type == 2:
            for i in range(A, B+1):
                if i == A or i == B:
                    bus_stop[i-1] += 1
                elif A % 2 == 0:
                    if i % 2 == 0:
                        bus_stop[i-1] += 1
                elif A % 2 == 1:
                    if i % 2 == 1:
                        bus_stop[i-1] += 1
        elif bus_type == 3:
            for i in range(A, B+1):
                if i == A or i == B:
                    bus_stop[i-1] += 1
                elif A % 2 == 0:
                    if i % 4 == 0:
                        bus_stop[i-1] += 1
                elif A % 2 == 1:
                    if i % 3 == 0 and i % 10 != 0:
                        bus_stop[i-1] += 1
    max_stop = 0
    max_stop_idx = 0
    for i, v in enumerate(bus_stop):
        if bus_stop[i] > max_stop:
            max_stop = v
            max_stop_idx = i
    print('#{} {}' .format(t, max_stop))