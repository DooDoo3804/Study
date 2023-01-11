# 1208_Flatten 풀이
# 2202-08-09
import sys
sys.stdin = open('input.txt', 'r')
for t in range(1, 11):
    D = int(input())
    boxes = list(map(int, input().split()))
    count = 0
    while count <= D:
        # 정렬
        for i in range(100):
            for j in range(0, i):
                if boxes[j] > boxes[i]:
                    boxes[j], boxes[i] = boxes[i], boxes[j]
        if count == D:
            print('#{} {}' .format(t, boxes[-1] - boxes[0]))
            break
        if boxes[-1] - boxes[0] > 1 :
            boxes[-1] -= 1
            boxes[0] += 1
            count += 1
        else:
            print('#{} {}' .format(t, boxes[-1] - boxes[0]))
            break