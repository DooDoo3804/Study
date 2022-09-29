import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
def cal_num(num1, num2, char):
    operator = {
        '+': lambda x,y : x+y,
        '*': lambda x,y : x*y,
        '-': lambda x, y: x - y,
        '/': lambda x, y: x // y,
    }
    return operator[char](num2, num1)
for t in range(1, 1+T):
    chars = list(map(str, input().split()))
    stack = []
    result = 0
    for char in chars:
        if char.isnumeric():
            stack.append(int(char))
        else:
            if char == '.':
                break
            elif len(stack) < 2 :
                result = 'error'
                break
            num1 = stack.pop()
            num2 = stack.pop()
            stack.append(cal_num(num1, num2, char))
    if len(stack) == 1 and result != 'error':
        result = stack[-1]
    else:
        result = 'error'
    print('#{} {}' .format(t, result))
