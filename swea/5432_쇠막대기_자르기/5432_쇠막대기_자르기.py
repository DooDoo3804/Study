# 5432_쇠막대기_자르기
# 2022-08-16
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, 1+T):
    pipe_list = list(str(input()))
    pipe_len = 0
    result = []
    for _ in pipe_list:
        pipe_len += 1
    i = st_pipe = 0
    while i <= pipe_len-1:
        if pipe_list[i] == '(' and pipe_list[i+1] == '(' :
            st_pipe += 1
            result.append(st_pipe)
            i += 1
        elif pipe_list[i] == '(' and pipe_list[i+1] == ')' :
            i += 2
            result.append(0)
        elif pipe_list[i] == ')':
            result.append(st_pipe)
            st_pipe -= 1
            i += 1
    stack = [0]
    count = multi = 0
    for pipe in result:
        if pipe == 0:
            count += multi
            continue
        elif stack[-1] == pipe:
            multi -= 1
            stack.pop()
        else:
            count += 1
            multi += 1
            stack.append(pipe)
    print('#{} {}' .format(t, count))


