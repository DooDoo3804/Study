import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
search1 = [[1, 0], [-1, 0], [0, 1], [0, -1],] # 십자 탐색 범위
search2 = [[1, 1], [-1, 1], [-1, -1], [1, -1],] # 대각선 탐색 범위

def change_color(x, y, c):
    """
    놓는 돌의 인덱스 x, y 와 돌 색 c를 받고 total_map에서 바꿀 수 있으면 변환

    돌을 x, y에 먼저 배치
    십자탐색과 대각선 탐색을 진행
    만약 바꿀 돌이 존재한다면 돌 색 변환
    Args:
        x (int): 놓은 돌의 행
        y (int): 놓은 돌의 열
        c (int):  놓은 돌의 색 1=흑 2=백

    Returns:
        list : 돌 색을 바꾸고 total_map을 반환
    """
    if c == 1 :
        c_prime = 2
    elif c == 2:
        c_prime = 1
    total_map[x][y] = c

    # 범위에 대해 탐색을 진행한다 1인 경우에 대해 살펴보면...
    # 1을 만나면 종료한다 / 나머지는 모두 spot_list에 추가
    # spot_list에 대해서 중간에 0이 전혀 존재하지 않고
    # 1이 존재하여 1과 1사이가 2로만 채워져 있는 경우 색 변환을 실시
    # 2이면 바꿔주고 1을 만나면 바꾸는 것 종료
    # 대각선도 같은 방법으로 진행
    for search in search1: # 십자 탐색 진행
        spot_list = []
        x_prime = x
        y_prime = y
        while True:
            x_prime += search[0]
            y_prime += search[1]
            if 0 <= x_prime < N and 0 <= y_prime < N:
                if total_map[x_prime][y_prime] == c:
                    spot_list.append(total_map[x_prime][y_prime])
                    break
                else:
                    spot_list.append(total_map[x_prime][y_prime])
            else:
                break
        if 0 not in spot_list and spot_list != [] and c in spot_list:
            for i, v in enumerate(spot_list):
                if v == c_prime:
                    total_map[x + (search[0] * (i + 1))][y + (search[1] * (i + 1))] = c
                else:
                    break
    for search in search2: # 대각선 탐색 진행
        spot_list = []
        x_prime = x
        y_prime = y
        while True:
            x_prime += search[0]
            y_prime += search[1]
            if 0 <= x_prime < N and 0 <= y_prime < N:
                if total_map[x_prime][y_prime] == c:
                    spot_list.append(total_map[x_prime][y_prime])
                    break
                else:
                    spot_list.append(total_map[x_prime][y_prime])
            else:
                break
        if 0 not in spot_list and spot_list != [] and c in spot_list:
            for i, v in enumerate(spot_list):
                if v == c_prime:
                    total_map[x + (search[0] * (i + 1))][y + (search[1] * (i + 1))] = c
                else:
                    break

for t in range(1, T+1):
    N, M = map(int, input().split())
    total_map = [[0 for _ in range(N)] for _ in range(N)]
    # 초기 맵을 생성한 다음 아래처럼 default를 배치
    total_map[N//2-1][N//2-1] = 2
    total_map[N//2-1][N//2] = 1
    total_map[N // 2][N // 2 - 1] = 1
    total_map[N // 2][N // 2] = 2

    # 돌을 추가할 때 마다 색을 변경
    for _ in range(M):
        x, y, c = map(int, input().split())
        change_color(x-1, y-1, c)

    count1 = 0
    count2 = 0
    # 최종 맵에서 1과 2를 카운트함
    for i in range(N):
        for j in range(N):
            if total_map[i][j] == 1:
                count1 += 1
            elif total_map[i][j] ==2 :
                count2 += 1
    print('#' + str(t) + ' ' + str(count1) + ' ' + str(count2))