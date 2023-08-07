# import sys
# n = int(sys.stdin.readline())
# array = []
# for i in range(n):
#     x, y = map(int, sys.stdin.readline().strip().split())
#     array.append([x, y, i, 0, 0])
#
# array.sort(key=lambda x: (x[1], x[0]))
# total_sum = [0]
# for i, a in enumerate(array):
#     total_sum.append(total_sum[i] + a[1])
#     a[3] = total_sum[i] + a[1]
#
# array.sort(key=lambda x: (x[0], x[1]))
# max_index = array[-1][0]
# sub_sum = [[0] for _ in range(max_index+1)]
# for i, a in enumerate(array):
#     color = sub_sum[a[0]]
#     color.append(color[-1] + a[1])
#     a[4] = color[-1]
# print(array)

import sys
n = int(sys.stdin.readline())
array = []
for i in range(n):
    sub_list = list(map(int, sys.stdin.readline().split()))
    array.append([sub_list, i, 0, 0])

array.sort(key=lambda x:(x[0][1], x[0][0], x[1]))
total_sum = [0]
pre = 0
temp = 0
for i, a in enumerate(array):
    if pre == a[0][1]:
        total_sum.append(total_sum[i])
        a[2] = total_sum[i]
        temp += a[0][1]

    else:
        total_sum.append(total_sum[i] + a[0][1] + temp)
        a[2] = total_sum[i] + a[0][1] + temp
        temp = 0

    pre = a[0][1]

array.sort(key=lambda x:(x[0][0], x[0][1], x[1]))
max_index = array[-1][0][0]
color_sum = [[0] for _ in range(max_index+1)]
pre = [0, 0]
temp = 0
for i, a in enumerate(array):
    length = len(color_sum[a[0][0]])
    if pre == a[0]:
        color_sum[a[0][0]].append(color_sum[a[0][0]][length-1])
        a[3] = color_sum[a[0][0]][length-1]
        temp += a[0][1]
    else:
        if pre[0] != a[0][0]:
            temp = 0
        color_sum[a[0][0]].append(color_sum[a[0][0]][length-1] + a[0][1] + temp)
        a[3] = color_sum[a[0][0]][-1]
        temp = 0
    pre = a[0]
array.sort(key=lambda x:x[1])
for a in array:
    print(a[2]-a[3])
