# 1486_장훈이의_높은_선반
# 2022-09-16

import sys
sys.stdin = open('input.txt', 'r')

def make_height(i):
    """
    인덱스 i를 받아 stack의 합을 구하고 B 이상이면 그 값을 반환하는 함수

    Params:
        i (int): height의 인덱스

    Returns:
        int: stack에 들어간 heights의 합
    """
    global sub_sum, result
    l = i+1
    for j in range(l, N):
        stack.append(heights[j])
        if sum(stack) < B:
            make_height(j)
        elif sum(stack) >= B:
            sub_sum = sum(stack)
        if B <= sub_sum <= result:
            result = sub_sum
        stack.pop()


T = int(input())
for t in range(1, 1+T):
    N, B = map(int, input().split())
    heights = list(map(int, input().split()))
    result = sum(heights)
    for i in range(N):
        stack = []
        sub_sum = 0
        stack.append(heights[i])
        make_height(i)
        if B <= sub_sum <= result:
            result = sub_sum
    print('#{} {}' .format(t, result-B))