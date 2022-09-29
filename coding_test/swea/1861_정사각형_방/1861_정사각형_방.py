# 1861_정사각형 방
# 2022-09-15

import sys
sys.stdin = open('input.txt', 'r')
sys.setrecursionlimit(10**6)

def bfs(i, j, start):
    """
    시작 위치 인덱스 i와 j와 start 값을 받아 bfs를 진행하고 sub_max 를 반환하는 함수

    Params:
        i (int): 인덱스 값 i
        j (int): 인덱스 값 j
        start (int): [i, j] 위치에 있는 값

    Returns:
        int : bfs 탐색을 진행하고 sub_max 값을 반환
    """
    global cnt, sub_max
    for area in search_area:
        next_i = i + area[0]
        next_j = j + area[1]
        if 0 <= next_j < N and 0 <= next_i < N:
            if room_list[next_i][next_j]-start == 1 and visited[next_i][next_j] == 0:
                visited[next_i][next_j] = 1
                cnt += 1
                i = next_i
                j = next_j
                bfs(i, j, room_list[i][j])
                visited[next_i][next_j] = 0
                if cnt > sub_max:
                    sub_max = cnt
                cnt -= 1
        else:
            pass
T = int(input())
for t in range(1, T+1):
    N = int(input())
    room_list = [[0 for _ in range(N)] for _ in range(N)]
    visited = [[0 for _ in range(N)] for _ in range(N)]

    for i in range(N):
        room_list[i] = list(map(int, input().split()))
    search_area = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    cnt = 0
    result = 0
    idx = []
    for i in range(N):
        for j in range(N):
            start = room_list[i][j]
            cnt = 1
            sub_max = 0
            bfs(i, j, start)
            # bfs를 진행하고 나온 값 sub_max가 result 보다 크면
            # 그 값을 start로 바꿔주고 같으면 추가하여 준다
            if sub_max > result:
                idx = [start]
                result = sub_max
            elif sub_max == result:
                idx.append(start)

    print('#{} {} {}' .format(t, min(idx), result))