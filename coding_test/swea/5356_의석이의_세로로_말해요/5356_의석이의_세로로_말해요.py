# 5356 의석이의 세로로 말해요
# 2022-08-16
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    test_list = [[''] * 15 for _ in range(15)]
    for row in range(5):
        for i, v in enumerate(list(map(str, input()))):
            test_list[row][i] = v
    print('#{}' .format(t), end=' ')
    for i in range(15):
        for j in range(5):
            if test_list[j][i] :
                print(test_list[j][i], end='')
    print()