from collections import deque

def solution(x, y, n):
    answer = 2134567890
    q = deque([(x,0)])
    visited = [False] * (y + 1)
    visited[x] = True
    
    while q :
        now_num, now_count = q.popleft()
        if now_num == y:
            return now_count
        elif now_num > y:
            continue
        for next in [now_num * 3, now_num * 2, now_num + n]:
            if next <= y and visited[next] == False:
                q.append((next, now_count + 1))
                visited[next] = True
    if answer == 2134567890: answer = -1
    return answer