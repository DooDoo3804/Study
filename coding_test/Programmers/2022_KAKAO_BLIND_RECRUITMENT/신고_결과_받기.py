def solution(id_list, report, k):
    stack = [[] for _ in range(len(id_list))]
    cnt = [0 for _ in range(len(id_list))]
    name_list = []
    for char in report:
        a, b = map(str, char.split())
        if b not in stack[id_list.index(a)]:
            stack[id_list.index(a)].append(b)
            cnt[id_list.index(b)] += 1
    for i, count in enumerate(cnt):
        if count >= k:
            name_list.append(id_list[i])
    answer = []
    for names in stack:
        t = 0
        for name in names:
            if name in name_list:
                t += 1
        answer.append(t)
    return answer