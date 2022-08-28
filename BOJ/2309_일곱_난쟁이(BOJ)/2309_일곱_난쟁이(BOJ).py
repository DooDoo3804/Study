import sys
sys.stdin = open('input.txt', 'r')

heights = []
for _ in range(9):
    heights.append(int(input()))
for i in range(9):
    for j in range(i):
        result = sum(heights) - heights[i] - heights[j]
        if result == 100:
            heights.pop(i)
            heights.pop(j)
            break
    if len(heights) == 7:
        break
heights = sorted(heights)
for height in heights:
    print(height)
