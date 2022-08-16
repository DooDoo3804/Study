# 5432_쇠막대기_자르기
# 2022-08-16
import pprint
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
    count = 0
    max_pipe = 0
    for v in result :
        count += 1
        if max_pipe < v:
            max_pipe = v
    pipe_line = [[0] * count for _ in range(max_pipe+1)]
    for i, v in enumerate(result):
        pipe_line[max_pipe-v][i] = 1
    # 맨 밑에 r 그 위로 1층 부터
    pprint.pprint(pipe_line)
    print(result)

