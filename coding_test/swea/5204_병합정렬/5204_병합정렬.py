# 5204_병합_정렬
# 2022-09-27
import sys
sys.stdin = open('input.txt', 'r')

from collections import deque
def merge_sort(m):
    """
    리스트 m을 받아 좌우 구간을 나눠 merge한 값을 반환하는 함수

    Params:
        m (list): 나뉜 숫자 리스트

    Returns:
        int: merge 함수를 실행 시킨 결과를 반환
    """
    if len(m) == 1:
        return m
    q = len(m) // 2
    l_list = deque()
    r_list = deque()
    for i in range(q):
        l_list.append(m[i])
    for j in range(q, len(m)):
        r_list.append(m[j])
    # 좌우 구간을 최소한으로 나눈다음 merge 함수 실행
    l_list = merge_sort(l_list)
    r_list = merge_sort(r_list)
    return merge(l_list, r_list)

def merge(l_list, r_list):
    """
    왼쪽 오른쪽 구간 리스트를 받아 이를 병합하여 반환하는 함수

    Params:
        l_list (list): 왼쪽 구간 리스트
        r_list (list): 오른쪽 구간 리스트

    Returns:
        list: 병합한 리스트를 반환

    """
    global cnt, result
    result = deque()
    if len(l_list) > 0 and len(r_list) > 0 and l_list[-1] > r_list[-1]:
        cnt += 1
    while len(l_list) > 0 or len(r_list) > 0:
        if len(l_list) > 0 and len(r_list) > 0:
            if l_list[0] <= r_list[0]:
                result.append(l_list.popleft())
            else:
                result.append(r_list.popleft())
        elif len(l_list) > 0:
            result.append(l_list.popleft())
        elif len(r_list) > 0:
            result.append(r_list.popleft())
    return result

T = int(input())
for t in range(1, 1+T):
    n = int(input())
    num_list = list(map(int, input().split()))
    cnt = 0
    result = []
    merge_sort(num_list)
    print('#{} {} {}' .format(t, result[n//2], cnt))





