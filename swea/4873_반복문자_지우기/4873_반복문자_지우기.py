# 4873_반복문자_지우기
# 2022-08-18
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, T+1):
    words = str(input())
    stack = []
    for word in words:
        if stack == []:
            stack.append(word)
        elif stack[-1] == word:
            stack.pop()
        else:
            stack.append(word)
    result = 0
    for _ in stack :
        result += 1
    print('#{} {}' .format(t,result))