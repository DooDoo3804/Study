# 5209_최소_생산_비용
# 2022-09-27
import sys
sys.stdin = open('input.txt', 'r')

def find_min(sub_result, idx):
    """
    중간 합 sub_result와 인덱스 idx를 받아 합을 계산하고 그 최솟값을 반환하는 함수

    Params:
        sub_result (int): result 보다 작은 중간까지의 합
        idx (int): 제품 깊이 idx

    Returns:
        (int): result보다 작은 sub_result라면 그 result 값을 반환
    """
    global result
    if idx == n and sub_result < result:
        result = sub_result
        return
    for i in range(n):
        # 탐색하지 않은 제품에 대해서 중간까지의 합이 계산한 result 보다 작은 경우만 합을 진행
        # 중간 합이 더 큰 경우에는 지나간다
        if i not in stack and sub_result+total_map[idx][i] < result:
            stack.append(i)
            sub_result += total_map[idx][i]
            idx += 1
            find_min(sub_result, idx)
            idx -= 1
            sub_result -= total_map[idx][i]
            stack.pop(-1)

T = int(input())
for t in range(1, 1+T):
    n = int(input())
    total_map = [[] for _ in range(n)]
    for i in range(n):
        total_map[i] = list(map(int, input().split()))
    stack = []
    idx = 0
    result = 10**n
    find_min(0, 0)
    print('#{} {}' .format(t, result))