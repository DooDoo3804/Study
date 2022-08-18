# 1234_비밀번호
# 2022-08-18
import sys
sys.stdin = open('input.txt', 'r')

for t in range(1, 11):
    str_len, N = map(str, input().split())
    stack = []
    for n in N:
        if stack == []:
            stack.append(n)
        elif n == stack[-1]:
            stack.pop()
        elif n != stack[-1]:
            stack.append(n)

    print('#{} {}' .format(t, ''.join(stack)))