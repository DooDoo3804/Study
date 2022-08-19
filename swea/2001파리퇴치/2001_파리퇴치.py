# 2001_파리퇴치
# 2022-08-19
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())

for t in range(1, T+1):
    N, M = map(int, input().split())
    fly_list = []
    for _ in range(N):
        fly_list.append(list(map(int, input().split())))
    # 탐색범위 설정
    search_area = []
    max_count = 0
    for i in range(M):
        for j in range(M):
            search_area.append([i,j])

    for i in range(N - M + 1):
        for j in range(N - M + 1):
            count = 0
            for area in search_area:
                count += fly_list[i+area[0]][j+area[1]]
            if max_count < count :
                max_count = count
    print('#{} {}' .format(t, max_count))




    # 5x5
    # 2x2
    # 0 0 0 0 0
    # 0 0 0 0 0
    # 0 0 0 0 0
    # 0 0 0 0 0
    # 0 0 0 0 0