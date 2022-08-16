# 1859_백만장자_프로젝트
# 2022-08-16
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    L = int(input())
    sell_list = list(map(int, input().split()))
    result = max_value = 0

    for i in range(L-1, -1, -1):
        if sell_list[i] > max_value:
            max_value = sell_list[i]
        else:
            result += max_value-sell_list[i]
    print('#{} {}' .format(t, result))