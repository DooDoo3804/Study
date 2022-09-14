numbers = list(input())
stack = []
for n in numbers:
    stack.append(int(n))
    if len(stack) == 2:
        if 0 in stack or 1 in stack:
            a = stack.pop()
            b = stack.pop()
            stack.append(a+b)
        else:
            a = stack.pop()
            b = stack.pop()
            stack.append(a*b)
print(stack[0])