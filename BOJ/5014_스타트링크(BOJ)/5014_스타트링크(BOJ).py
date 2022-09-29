# 5014_스타트링크(BOJ)
# 2022-09-29

F, S, G, U, D = map(int, input().split())
stack = [F] * (F+1)
visited = [0] * (F+1)
flr = [S]
visited[S] = 1
stack[S] = 0
cnt = 0
while flr:
    cnt += 1
    for _ in range(len(flr)):
        now = flr.pop(0)
        if now+U <= F and stack[now+U] > cnt:
            stack[now + U] = cnt
            if visited[now + U] == 0:
                visited[now + U] = 1
                flr.append(now + U)
        if  F > now-D > 0 and stack[now - D] > cnt:
            stack[now - D] = cnt
            if visited[now - D] == 0:
                visited[now - D] = 1
                flr.append(now - D)

if stack[G] == F:
    print("use the stairs")
else:
    print(stack[G])