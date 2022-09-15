# 5178_노드의_합
# 2022-09-15
import sys
sys.stdin = open('input.txt', 'r')


def cal_tree(i):
    """
    노드 번호 i 부터 순회 하면서 자식 노드들의 값을 더하여 반환하는 함수
    Args:
        i (int): 찾고자 하는 값의 노드 번호

    Returns:
        int : i 노드 번호의 값을 반환
    """
    global result
    if par[i]:
        cal_tree(ch1[i])
        cal_tree(ch2[i])
        result += stack[i]

T = int(input())
for t in range(1, T+1):
    n, m, l = map(int, input().split())
    par = [0] * (n+1)
    ch1 = [0] * (n+1)
    ch2 = [0] * (n+1)
    stack = [0] * (n+1)
    result = 0
    for i in range(1, n+1) :
        par[i] = i//2
        if i * 2 < n + 1:
            ch1[i] = i*2
        if i*2+1 < n+1:
            ch2[i] = i*2+1
    for i in range(1, m+1):
        i, v = map(int, input().split())
        stack[i] = v
    cal_tree(l)
    print('#{} {}' .format(t, result))
