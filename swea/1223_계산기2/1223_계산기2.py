# 1223_계산기2
# 2022-08-26
import sys
sys.stdin = open('input.txt', 'r')

def char_cal(num1, num2, op):
    """
    num1 num2를 받아 op 연산을 수행하고 결과값을 반환하는 함수

    Args:
        num1 (int): num1
        num2 (int): num2
        op (str): 연산자 '+' 또는 '*'

    Returns:
        int : 연산 결과값

    """
    ops = {
        '+': lambda x, y: x + y,
        '*': lambda x, y: x * y,
    }
    return ops[op](num2, num1)

operator = ['+','*',]

for t in range(1, 11):
    n = int(input())
    stack = [-1]
    chars = list(map(str, input()))
    postfix = ''
    # 후위 표기법으로 변환
    # + 와 *만 있으므로 +면 앞의 *를 모두 pop해주고
    # 나머지의 겨우 모두 stack에 넣는다
    for i in range(n):
        if chars[i] not in operator:
            postfix += chars[i]
        else:
            if chars[i] == '+':
                if stack[-1] == '*':
                    while stack[-1] == '*':
                        postfix += stack[-1]
                        stack.pop()
                stack.append(chars[i])
            elif chars[i] == '*':
                stack.append(chars[i])
    # stack을 모두 비워준다
    while stack[-1] != -1:
        postfix += stack[-1]
        stack.pop()

    # 앞에서 부터 차례로 계산
    # 숫자는는 stack에 넣고 연산자는 그에 맞는 계산 수행
    stack = []
    for char in postfix:
        if char not in operator:
            stack.append(int(char))
        elif char in operator:
            num1 = stack.pop()
            num2 = stack.pop()
            stack.append(char_cal(num1, num2, char))
    print('#{} {}' .format(t, stack[-1]))