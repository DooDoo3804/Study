# 1238_Contact
# 2022-09-13
import sys
sys.stdin = open('input.txt', 'r')

def signal():
    """
    시작 지점부터 신호를 보내서 깊이 탐색을 진행하는 함수

    Returns:
        list : stack에 같은 깊이의 노드들을 반환한다

    """
    global result
    sub_stack = []
    for node in stack[0]:
        if visited[node] == 0:
            visited[node] = 1
            for i, v in enumerate(arr[node]):
                if visited[v] == 0:
                    sub_stack.append(v)

    # 같은 깊이의 노드들을 탐색하여 방문하지 않았다면 추가하고 방문한 노드들 stack[0]을 지운다
    a = stack.pop(0)
    stack.append(sub_stack)
    if stack == [[]]:
        result = a

for t in range(1, 11):
    l, s = map(int, input().split())
    arr = [[] for _ in range(101)] * (101)
    infos = list(map(int, input().split()))
    visited = [0] * (101)
    stack = []
    stack.append(arr[s])
    visited[s] = 1
    result = []
    for i in range(l//2):
        arr[infos[i*2]].append(infos[i*2+1])

    while stack != [[]]:
        signal()

    print('#{} {}' .format(t, max(result)))
