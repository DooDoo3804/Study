# 5102_노드의_거리
# 2022-08-25
import copy
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
def bfs(queue):
    """
    queue list를 받아 깊이가 깊어질 수록 count를 증가시켜 count를 반환하는 함수

    현재의 queue를 받아오면 현재는 같은 깊이의 노드들이다 이들에 대해 bfs를 진행하고
    모두 진행했다면 count 를 1 증가시킨다(깊이 +1)
    이후 새로 추가된 queue에 대해 같은 방법으로 탐색을 진행한다 이때 deepcopy로 queue를
    복사한 다음 이를 사용한다 탐색을 다 진행했는데 더이상 할 것이 없는 queue가 빈상태이면 종료한다

    Args:
        queue (list): 현재 같은 깊이의 노드들

    Returns:
        int : global count 값
    """
    global count
    d_queue = copy.deepcopy(queue)
    # 변화시킬 d_queue를 queue에서 deepcopy 해온다
    # 같은 깊이의 모든 노드들에 대해 bfs를 진행한다
    # 모든 탐색을 완료하면 count를 1 증가시킨다
    for inner in d_queue:
        queue.pop(0)
        for node in nodes[inner]:
            if node not in visited:
                queue.append(node)
                visited.append(node)
            if node == G:
                count += 1
                return
    count += 1
    if queue == []:
        count = 0
        return
    bfs(queue)

for t in range(1, 1+T):
    V, E = map(int, input().split())
    nodes = [[] for _ in range(V+1)]

    # 주어지는 노드와 간선이 대해서 쌍방으로 모두 추가해 준다
    for _ in range(E):
        i, n = map(int, input().split())
        nodes[i].append(n)
        nodes[n].append(i)

    S, G = map(int, input().split())
    visited = []
    queue = []
    visited.append(S)
    queue.append(S)
    # 방문 여부 visited와 현재 queue에 현재 위치 S를 추가해준다
    count = 0
    bfs(queue)
    print('#{} {}' .format(t, count))