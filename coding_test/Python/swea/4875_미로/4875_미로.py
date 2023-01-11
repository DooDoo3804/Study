# 4875_미로
# 2022-08-23
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())

# 현재 위치 인덱스 리스트를 받고 탐색을 진행하여 result를 반환하는 함수
def find3(now_index):
    global now, visited, result
    row = col = 0
    # 모든 방향 리스트에 대해서 순차적으로 탐색
    for direction in choose_direction:
        # 이동할 row col 계산
        row = now_index[-1][0] + direction[0]
        col = now_index[-1][1] + direction[1]
        # maze 범위 내에 있고, 3이라면 도착. 종료
        if 0 <= row < N and 0 <= col < N and maze[row][col] == 3:
            now_index.append([row, col])
            break
            # 범위내에 있고, 3이 아니라면
        if 0 <= row < N and 0 <= col < N:
            # 방문 했던 곳이라면 그냥 패스
            if visited[row][col] == 1:
                continue
            # 만약 길인 0이 아니라면 그냥 패스
            elif maze[row][col] != 0 :
                continue
            # 갈 수 있는 곳이라면 visited 체크하고 now_index에 이동할 위치를 추가
            # 이동한 부분에서 find3을 다시 진행
            else:
                visited[row][col] = 1
                now_index.append([row, col])
                find3(now_idx)
                # 모든 탐색을 마치고 빠져나왔을 때 도착점을 갖고 있다면 종료
                if end in now_index:
                    result = 1
                    break
    # 위의 모든 경우가 아니라면 원래 자리로 돌아간다
    # now_index.pop()을 하면 전 위치로 이동
    else:
        now_index.pop()
    return result

for t in range(1, T+1):
    N = int(input())
    maze = []
    result = 0
    choose_direction = [[-1, 0],[0, 1],[0 ,-1],[1, 0]]
    # 상 우 좌 하 탐색
    # 방문 여부 확인 visited
    visited = [[0 for _ in range(N)] for _ in range(N)]

    # 2와 3 위치 찾기
    # 미로 받기
    for i in range(N):
        maze.append(list(map(int, input())))
        for j in range(N):
            if maze[i][j] == 2:
                start = [i, j]
            elif maze[i][j] == 3:
                end = [i, j]

    now_idx = [start]
    find3(now_idx)
    # 현재 위치를 find3에 집어 넣고 탐색 시작
    print('#{} {}'. format(t, result))
