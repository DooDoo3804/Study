import sys
sys.stdin = open('input.txt', 'r')

def dfs(node):
    visited[node] = 1
    for route in routes[node]:
        if visited[route] == 0:
            dfs(route)

for _ in range(10):
    t, N = map(int, input().split())
    route_input = list(map(int, input().split()))
    routes = [[] for _ in range(100)]
    visited = [0 for _ in range(100)]
    while route_input:
        end_route = route_input.pop()
        start_route = route_input.pop()
        routes[start_route].append(end_route)
    dfs(0)
    print('#{} {}' .format(t, visited[99]))
