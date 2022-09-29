# 1232_사칙연산
# 2022-09-15

import sys
sys.stdin = open('input.txt', 'r')

def cal_tree(i):
    """
    i 부터 시작하여 후위 탐색을 진행하면서 계산을 진행하는 함수

    Params:
        i (int): 루트 노드의 인덱스

    Returns:
        list : form에 계산하는 과정을 담고 마지막 결과를 반혼

    """
    if par[i]:
        cal_tree(int(ch1[i]))
        cal_tree(int(ch2[i]))
        if par[i].isnumeric():
            form.append(par[i])
        else:
            form.append(par[i])
            b = form.pop()
            a = form.pop()
            c = form.pop()
            form.append(my_cal(c,a,b))

def my_cal(x, y, op):
    """
    숫자 x와 y를 받고 연산자 op에 대해 계산을 수행하고 그 값을 반환하는 함수

    Params:
        x (int): 숫자 1
        y (int): 숫자 2
        op (char): 연산자

    Returns:
        int : 두 숫자를 연산하고 나온 값을 반환
    """
    ops = {
        '+' : lambda x,y : x+y,
        '-' : lambda x,y : x-y,
        '*' : lambda x,y : x*y,
        '/' : lambda x,y : x/y,
    }
    return ops[op](int(x), int(y))

for t in range(1, 11):
    n = int(input())
    par = [0] * (n+1)
    ch1 = [0] * (n+1)
    ch2 = [0] * (n+1)
    form = []
    # 1이 항상 정점
    for i in range(1, n+1):
        input_line = list(map(str, input().split()))
        idx = int(input_line[0])
        if input_line[1].isnumeric():
            par[idx] = input_line[1]
        else:
            par[idx] = input_line[1]
            ch1[idx] = input_line[2]
            ch2[idx] = input_line[3]
    cnt = 0
    cal_tree(1)
    print('#{} {}' .format(t, int(*form)))
