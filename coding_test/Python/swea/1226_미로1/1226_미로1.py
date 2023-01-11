# 1226_미로1
# 2022-08-25
import sys
sys.stdin = open('input.txt', 'r')
directions = [[1, 0], [-1, 0], [0, 1], [0, -1],]
def bfs(node):
    """
    현재 위치의 node 좌표를 받아서 길을 찾아 있으면 1 없으면 0을 반환하는 함수

    현재 node 좌표를 받아서 4방향에 대해 탐색하고 길이 있고 방문하지 않았다면
    move_queue에 추가한다. 만약 도착지에 간다면 result = 1을 반환하고 종료한다
    만약 도착지에 다다르지 못하고 모든 경로를 탐색했다면 result = 0을 반환

    Args:
        node (list): 현재 위치에 대한 리스트 [행, 열]

    Returns:
        int : result의 값을 반환
    """
    global result
    now = node
    move_queue.pop(0)
    for direction in directions:
        x = direction[0] + now[0]
        y = direction[1] + now[1]
        if maze[x][y] == 0 and [x, y] not in visited:
            move_queue.append([x, y])
            visited.append([x, y])
        elif maze[x][y] == 3 and [x, y] not in visited:
            move_queue.append([x, y])
            result = 1
            return
    if move_queue == []:
        result = 0
        return
    bfs(move_queue[0])


for _ in range(10):
    t = int(input())
    maze = []
    for _ in range(16):
        maze.append(list(map(int, input())))

    # 지도를 받고 처음 출발 위치를 찾는다
    for i in range(16):
        for j in range(16):
            if maze[i][j] == 2:
                start = [i, j]
                break
    now = start
    move_queue = []
    visited = []
    move_queue.append(now)
    visited.append(now)
    # 처음 위치를 기록해 두고 bfs에 넣어서 결과를 도출한다
    bfs(now)
    print('#{} {}' .format(t, result))