# 5105_미로의_거리
# 2022-08-25
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
directions = [[-1, 0], [0, 1], [0, -1], [1, 0]]
# 상 우 좌 하
def find_way(now):
    """
    현재 위치를 받아 movelist를 반환하는 함수

    현재 위치에서 모든 direction을 탐색하고 움직일 수 있으면
    이동하여 다시 탐색을 진행한다
    3에 도착하면 동작을 끝내고 movelist를 반환한다

    Args:
        now (list): 현재 위치의 인덱스 리스트 [행,렬]

    Returns:
        list : movelist를 반환한다
    """
    move_list.append(now)
    visited[now[0]][now[1]] = 1
    if move_list[-1] == end:
        return
    for direction in directions:
        x = now[0]+direction[0]
        y = now[1]+direction[1]
        if 0 <= x < N and 0 <= y < N:
            if maze[x][y] != 1 and visited[x][y] == 0:
                find_way([x, y])
                if move_list[-1] == end:
                    return
                move_list.pop()
            else:
                continue
    return

for t in range(1, 1+T):
    N = int(input())
    maze = []
    end = []
    visited = [[0 for _ in range(N)]for _ in range(N)]
    move_list = []
    for i in range(N):
        maze.append(list(map(int, input())))
    # 시작점과 끝점을 찾아 각각 start와 end에 할당한다
    for i in range(N):
        for j in range(N):
            if maze[i][j] == 2:
                start = [i, j]
            if maze[i][j] == 3:
                end = [i, j]
    now = start
    find_way(now)
    result = 0
    # move_list에서 맨처음과 마지막을 빼면 움직인 칸의 개수를 알 수 있다
    # 이때 뺀 결과값이 0보다 작으면 경로가 없는 경우이므로 0을 반환한다
    for _ in move_list:
        result += 1
    result -= 2
    if result < 0:
        result = 0
    print('#{} {}'.format(t, result))
