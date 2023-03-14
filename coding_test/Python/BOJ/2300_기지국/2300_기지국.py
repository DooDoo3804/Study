# 2300_기지국
# 2022-08-18

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
x1 = x2 = y1 = y2 = result = 0
for i in coord:
    x2 = i[0]
    y2 = i[1]
    width = x2 - x1
    height = y2 - y1
    if x1 == 0 and y1 == 0:
        x1 = x2
        y1 = y2
        continue
    elif height == 0:
        continue
    if y2 < 0 :
        y2 = - y2
    if width/2 >= y2:
        result += width
        x1 = x2 = y1 = y2 = 0
print(result)