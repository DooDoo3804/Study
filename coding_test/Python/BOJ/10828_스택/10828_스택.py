import sys
n = int(sys.stdin.readline())
stack = []
for _ in range(n):
    input_list = sys.stdin.readline().split()
    first = input_list[0]

    if first == "push":
        stack.append(int(input_list[1]))
    elif first == "top" :
        if len(stack):
            print(stack[-1])
        else:
            print(-1)
    elif first == "size":
        print(len(stack))
    elif first == "empty":
        if len(stack):
            print(0)
        else:
            print(1)
    elif first == "pop":
        if len(stack):
            print(stack.pop())
        else:
            print(-1)
