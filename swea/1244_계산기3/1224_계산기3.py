# 1224_계산기3
# 2022-08-23
import sys
sys.stdin = open('input.txt', 'r')

for t in range(1, 10+1):
    top = -1
    stack = []
    L = int(input())
    chars = str(input())
    operator = ['(', '+', '*', ')']
    prime = {'(':0, '+':1, '*':2}
    # 연산 함수
    def ops(num1, num2, op):
        pos = {
            '+': lambda x, y: x+y,
            '*': lambda x, y: x * y,
        }
        return pos[op](num2, num1)

    # 후위 표기법
    postfix = ''
    for i in range(L):
        if chars[i] == '(':
            stack.append(chars[i])
            top += 1
        elif chars[i] in prime and prime[chars[i]] >= prime[stack[top]]:
            stack.append(chars[i])
            top += 1
        elif chars[i] in prime and prime[chars[i]] < prime[stack[top]]:
            while True:
                postfix += stack[top]
                top -= 1
                stack.pop()
                if prime[chars[i]] > prime[stack[top]]:
                    stack.append(chars[i])
                    top += 1
                    break
        elif chars[i] == ')':
            while True:
                postfix += stack[top]
                top -= 1
                stack.pop()
                if stack[top] == '(':
                    top -= 1
                    stack.pop()
                    break
        else:
            postfix += chars[i]

    # 후위 표기법 계산
    cal_stack = []
    top = 0
    for char in postfix:
        if char not in operator:
            cal_stack.append(int(char))
            top += 1
        elif char in operator:
            num1 = cal_stack.pop()
            num2 = cal_stack.pop()
            result = ops(num1, num2, char)
            cal_stack.append(result)
            top -= 1

    print('#{} {}' .format(t, result))