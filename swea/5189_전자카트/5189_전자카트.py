# 5189_전자카트
# 2022-09-22

import sys
sys.stdin = open('input.txt', 'r')

def find_way(sub_stack):
    """
    경로를 탐색하여 방문하지 않은 경우 추가하고 그 list에 대해 cal을 실행하는 함수
    Params:
        sub_stack (list): 경로를 기록해 가는 list

    Returns:
        int: cal을 실행하고 그 결과를 반환
    """
    if len(sub_stack) == n:
        sub_stack.append(1)
        cal(sub_stack)
        sub_stack.pop(-1)
        return
    for i in num_list:
        if visited[i] == 0:
            visited[i] = 1
            sub_stack.append(i)
            find_way(sub_stack)
            sub_stack.pop(-1)
            visited[i] = 0

def cal(stack):
    """
    stack을 받아 인덱스에 맞게 계산하고 그 값을 반환하는 함수
    Params:
        stack (list): 경로의 인덱스

    Returns:
        int: result보다 작은 경우 그 값 result를 반환
    """
    global result
    index = []
    for j in range(0, len(stack)-1):
        index.append([stack[j], stack[j+1]])
    sub_sum = 0
    for idx in index:
        sub_sum += map_lilst[idx[0]-1][idx[1]-1]
    if result > sub_sum:
        result = sub_sum

T = int(input())
for t in range(1, 1+T):
    n = int(input())
    map_lilst = [[] for _ in range(n)]
    for i in range(n):
        map_lilst[i] = (list(map(int, input().split())))
    stack = []
    sub_stack = [1]
    num_list = [i for i in range(1, n+1)]
    visited = [0] * (n+1)
    visited[1] = 1
    visited[0] = 1
    result = 10 ** n
    find_way(sub_stack)
    print('#{} {}' .format(t, result))
