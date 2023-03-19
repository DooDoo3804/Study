import sys
n = int(input())
for _ in range(n):
    answer = "YES"
    stack = []
    line = list(sys.stdin.readline().rstrip())
    for s in line:
        if s == '(':
            stack.append(s)
        elif s == ')' and stack == []:
            answer = "NO"
            break
        elif s == ')' and stack[-1] == '(':
            stack.pop()
        elif s == ')' and stack[-1] != '(':
            answer = "NO"
            break
    if stack != []:
        answer = "NO"
    print(answer)