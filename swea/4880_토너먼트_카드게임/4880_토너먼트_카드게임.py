# 4880_토너먼트_카드게임
# 2022-08-23
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())

# start, (end+start)//2
# (end+start)//2+1, end

def winner(pre, stf, pre_idx, stf_idx):
    if pre == stf:
        return pre, pre_idx
    elif (pre, stf) == (1, 3) or (pre, stf) == (3, 1):
        if pre == 1:
            return pre, pre_idx
        else:
            return stf, stf_idx
    else :
        if pre > stf:
            return pre, pre_idx
        else:
            return stf, stf_idx

def div_area(array):
    cnt = 0
    pre_area = stf_area = []
    pre_idx = stf_idx = 0
    for i, v in enumerate(array):
        if i == i // 2:
            pre_area.append(v)
            pre_idx += 1
        else :
            stf_area.append(v)
            stf_idx += 1
    for _ in pre_area:
        cnt += 1
        if cnt > 2:
            div_area(pre_area)
    cnt = 0
    for _ in stf_area:
        cnt += 1
        if cnt > 2:
            div_area(stf_area)
    return

for t in range(1, T+1):
    students = int(input())
    game_list = list(map(int, input().split()))
    cnt = 0
    students_idx = []
    for i in range(students):
        students_idx.append(i+1)


