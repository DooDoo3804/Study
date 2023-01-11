# 1865_동철이의_일_분배
# 2022-09-27
import sys
sys.stdin = open('input.txt', 'r')

def cal_per():
    global cnt, result, sub_result
    cnt += 1
    if cnt == n :
        if sub_result > result:
            result = sub_result
        return
    for j in range(n):
        if j not in stack:
            if work[cnt][j]:
                stack.append(j)
                sub_result *= work[cnt][j]/100
                cal_per()
                cnt -= 1
                stack.pop(-1)
                sub_result /= work[cnt][j]/100
            else:
                return



T = int(input())
for t in range(1, 1+T):
    n = int(input())
    work = [[]for _ in range(n)]
    for i in range(n):
        work[i] = list(map(int, input().split()))
    i = 0
    cnt = 0
    result = float(10**(-n))
    sub_result = float(1)
    stack = []
    for i in range(n):
        if work[cnt][i]:
            stack.append(i)
            sub_result *= work[cnt][i]/100
            cal_per()
            cnt -= 1
            stack.pop(-1)
            sub_result /= work[cnt][i]/100
    print(result*100)