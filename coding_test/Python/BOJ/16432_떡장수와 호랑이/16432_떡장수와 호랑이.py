import sys
sys.setrecursionlimit(10000)
n = int(sys.stdin.readline().strip())
cake = []
for _ in range(n):
    input = sys.stdin.readline().strip()
    cake.append(input.split()[1:])


def find(d, c):
    global flag
    if d == n:
        flag = True
        for r in result:
            print(r)
        exit()

    for i, v in enumerate(cake[d]):
        if d == 0:
            check_list[d+1][int(v)] = 1
            result.append(v)
            find(d+1, v)
            result.pop()
        elif v != c and not check_list[d+1][int(v)]:
            check_list[d+1][int(v)] = 1
            result.append(v)
            find(d+1, v)
            result.pop()


result = []
flag = False
check_list = [[0 for _ in range(10)] for _ in range(n+1)]
find(0, '0')
print(-1)