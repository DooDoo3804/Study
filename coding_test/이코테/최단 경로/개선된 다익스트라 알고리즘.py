import heapq

import heapq, sys
input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())
start = int(input())
graph = [[] for i in range(n+1)]
distance = [INF] * (n+1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

def dijstra(start):
    """
    시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입함
    다른 노드로 가는 가장 짧은 거리를 구하는 함수

    Params :
        start (int): 시작 노드

    Returns :
        list : distance에 가장 짧은 거리를 담는다
    """
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
dijstra(start)
for i in range(1, n+1):
    if distance[i] == INF:
        print("INFINITY")
    else :
        print(distance[i])