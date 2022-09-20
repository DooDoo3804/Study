N = int(input())
K = int(input())
total_map = [[0 for _ in range(N)] for _ in range(N)]
movement = [[0 for _ in range(N)] for _ in range(N)]
for k in range(K):
    i, j = map(int, input().split())
    total_map[i][j] = 1
L = int(input())
stack = []

for l in range(L):
    stack.append(list(map(str,input().split())))
length = 1
cnt = 0
directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
def change_direction(i, d):
    if d == 'D':
        i += 1
    else :
        i -= 1
    if i == -1 :
        i = 3
    elif i == 4 :
        i = 0

while True:
