# 5714_subtree
# 2022-09-15

import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
def count_tree(i):
    """
    노드 i 부터 탐색하면서 자식 노드들을 카운트하는 함수

    Params:
        i (int): 탐색 시작하는 노드 번호

    Returns:
        int : 총 자식 노드를 카운트한 cnt를 반환
    """
    global cnt
    if par[i]:
        cnt += 1
        count_tree(ch1[i])
        count_tree(ch2[i])

for t in range(1, T+1):
    e, n = map(int, input().split())
    nodes = list(map(int, input().split()))
    par = [0] * (e+2)
    ch1 = [0] * (e+2)
    ch2 = [0] * (e+2)
    index = 0
    value = 0
    for i, v in enumerate(nodes):
        if i % 2 == 0:
            index = v
        elif i % 2 == 1:
            value = v
            if ch1[index] == 0 :
                ch1[index] = value
                par[value] = index
            else :
                ch2[index] = value
                par[value] = index

    # 루트 노드 찾기
    root = 0
    for i, v in enumerate(par):
        if i != 0 and v == 0:
            root = i

    cnt = 0
    count_tree(n)
    print('#{} {}' .format(t, cnt))