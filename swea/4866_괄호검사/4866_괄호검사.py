# 4866_괄호검사
# 2022-08-18
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, 1+T):
    str_list = list(input())
    stack = []
    check_list = ['(', ')', '{', '}']
    result = 1
    for s in str_list:
        if s in check_list:
            if s == ')':
                if stack == [] or stack[-1] != '(':
                    result = 0
                    break
                else :
                    stack.pop()
            elif s == '}':
                if stack == [] or stack[-1] != '{':
                    result = 0
                    break
                else :
                    stack.pop()
            else :
                stack.append(s)
    if stack != []:
        result = 0
    print('#{} {}' .format(t, result))