# 5789_현주의_상자_바꾸기
# 2022-08-09
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    N, Q = map(int, input().split())
    boxes = ['0'] * N
    for q in range(1, Q+1):
        L, R = map(int, input().split())
        for i in range(L-1, R):
            boxes[i] = q
    print('#{}' .format(t), *boxes)