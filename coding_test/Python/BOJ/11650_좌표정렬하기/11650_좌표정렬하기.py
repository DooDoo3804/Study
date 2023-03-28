n = int(input())
coord_list = []
for _ in range(n):
    coord_list.append(list(map(int, input().split())))
coord_list.sort(key=lambda x: (x[0], x[1]))

for a in coord_list:
    print(a[0], a[1])