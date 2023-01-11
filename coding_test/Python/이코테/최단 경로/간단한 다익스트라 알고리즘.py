import sys
input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())
start = int(input())
graph = [[] for i in range(n+1)]
visited = [False] * (n+1)
distance = [INF] * (n+1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append(b, c)
    
def get_smallest_node():
    """
    방문하지 않은 노드 중에서, 가장 최단 거리가 짧은 노드의 번호를 반환하는 함수
    
    Return : 
        int : 가장 최단 거리가 짧은 노드의 인덱스
    """
    min_value = INF
    index = 0
    for i in range(1, n+1):
        if distance[i] < min_value and not visited[i]:
            min_value = distance[i] 
            index = i
    return index

def dijkstra(start):
    """
    시작 노드를 제외하고 가장 짧은 노드를 찾는 get_smallest_node를 수행하는 함수

    Params :
        start (int): 시작 노드 start

    Returns :
        int : get_smallest_node를 진행하여 인덱스 반환
    """
    distance[start] = 0
    visited[start] = True
    for j in graph[start]:
        distance[j[0]] = j[1]
    for i in range(n-1):
        now = get_smallest_node()
        visited[now] = True
        for j in graph[now]:
            cost = distance[now] + j[1]
            if cost < distance[j[0]]:
                distance[j[0]] = cost

dijkstra(start)

for i in range(1, n+1):
    if distance[i] == INF:
        print("INFINITY")
    else:
        print(distance[i])