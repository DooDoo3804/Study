import sys
n, m = map(int, sys.stdin.readline().split())
count_map = [0 for _ in range(n)]
pre_map = [[[]] for _ in range(n)]
# []
for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    pre_map[b-1][0].append(a)
for i in range(n):
    pre_map[i].append(i+1)

pre_map.sort(key=lambda x:len(x[0]))

count = 0
while 0 in count_map:
    count += 1
    for node in pre_map:
        if len(node[0]) == 0 and count_map[node[1]-1] == 0:
            count_map[node[1] - 1] = count
    next_list = []
    for node in pre_map:
        if len(node[0]):
            sub_list = []
            for n in node[0]:
                if count_map[n-1] == 0:
                    sub_list.append(n)
            next_list.append([sub_list, node[1]])
    pre_map = next_list

print(*count_map)
