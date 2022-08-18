import sys
sys.stdin = open('input.txt', 'r')
T = int(input())

coord = []
for t in range(T):
    coord.append(list(map(int, input().split())))
width = height = 0
for i in range(T):
    for j in range(i):
        if coord[j][0] > coord[i][0]:
            coord[j], coord[i] = coord[i], coord[j]
x1 = x2 = y1 = y2 = result = width = lastx = lasty = lastwidth = 0
for i in coord:
    x2 = i[0]
    y2 = i[1]
    width = x2 - x1
    height = y2 - y1
    if x1 == 0 and y1 == 0:
        if i == coord[-1]:
            result -= lastwidth
            width = x2 - lastx
            result += width
            break
        x1 = x2
        y1 = y2
        continue
    elif height == 0:
        continue
    if y2 < 0 :
        y2 = - y2
    if width/2 >= y2:
        result += width
        lastwidth = width
        lastx = x1
        lasty = y1
        x1 = x2 = y1 = y2 = 0
print(result)