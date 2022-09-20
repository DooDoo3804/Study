N, M, K, X = map(int, input().split())
nodes = [[] for _ in range(N+1)]
for _ in range(M):
    i, j = map(int, input().split())
    nodes[i].append(j)
stack = [nodes[X]]
result = [N+1] * (N+1)
depth = 0
def dfs(stack):
    global depth
    sub_stack = []
    depth += 1
    for node in stack[0]:
        for i in nodes[node]:
            sub_stack.append(i)
        if depth < result[node]:
            result[node] = depth
    if sub_stack != []:
        stack.append(sub_stack)
        stack.pop(0)
        dfs(stack)
dfs(stack)
result_list = []
for i, v in enumerate(result):
    if v == K:
        result_list.append(i)
if result_list == []:
    print(-1)
else:
    for num in result_list:
        print(num)

# dfs로 하면 편함
# 다시 해야함
