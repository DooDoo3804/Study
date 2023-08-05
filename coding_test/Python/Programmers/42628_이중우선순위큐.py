import heapq
def solution(operations):
    q = []
    for v in operations:
        operator, num = map(str, v.split())
        if operator == "I":
            heapq.heappush(q, int(num))
        elif operator == "D" and q == []:
            continue
        elif operator == "D" and int(num) == 1:
            q.pop(-1)
        elif operator == "D" and int(num) == -1:
            heapq.heappop(q)
    if q != []:
        answer = [max(q), min(q)]
    else :
        answer = [0, 0]
    return answer