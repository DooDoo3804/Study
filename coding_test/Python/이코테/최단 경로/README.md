# 정렬

> 가장 짧은 경로를 찾는 알고리즘



### 다 익스트라 최단 경로 알고리즘

> 여러 개의 노드가 있을 때 특정한 노드에서 출발하여 다른 노드로 가는 각각의 최단 경로를 구해주는 알고리즘이다. 음의 간선이 없으면 모두 가능

1. 출발 노드 설정
2. 최단 거리 테이블을 초기화
3. 방문하지 않은 노드 중에서 최단 거리가 갖아 짧은 노드를 선택
4. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신
5. 위 3/4를 반복

각 노드에 대한 현재까지의 최단 거리 정보를 항상 1차원 리스트에 저장하며 리스트를 계속 갱신한다는 특징



#### 간단한 다익스트라 알고리즘

모든 노드에 대해서 탐색하는 알고리즘

```python
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
```



#### 개선된 다익스트라 알고리즘

heapq를 사용

운선순위가 가장 높은 데이터를 가장 먼저 삭제 / 우선 순위 큐에 사용

```python
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
```



### 플로이드 워셜 알고리즘

> 한 지점에서 다른 특정 지점까지의 최단 경로를 구해야 하는 경우에 사용할 수 있는 알고리즘
>
> 모든 지점에서 다른 모든 지점까지의 최단 경로를 모두 구해야 하는 경우

```python
INF = int(1e9)

n = int(input())
m = int(input())
graph = [[INF] * (n-1) for _ in range(n+1)]

for a in range(1, n+1):
    for b in range(1, n+1):
        if a == b:
            graph[a][b] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a][b] = c

for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])
for a in range(1, n+1):
    for b in range(1, n+1):
        if graph[a][b] == INF :
            print("INFINITY", end=" ")
        else:
            print(graph[a][b], end=" ")
    print()
```

