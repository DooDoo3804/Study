import sys

loop = True
while loop:
    answer = 'yes'
    stack = []
    line = list(sys.stdin.readline().rstrip())
    if line == ['.']:
        break
    for s in line:
        if s == '(' or s == '[':
            stack.append(s)
        elif s == ')':
            if stack == []:
                answer = 'no'
                break
            elif stack[-1] == '(':
                stack.pop()
            elif stack[-1] != '(':
                answer = 'no'
                break
        elif s == ']':
            if stack == []:
                answer = 'no'
                break
            elif stack[-1] == '[':
                stack.pop()
            elif stack[-1] != '[':
                answer = 'no'
                break
        elif s == '.':
            break
    if stack != []:
        answer = 'no'
    print(answer)
