import math
def solution(n, k):
    a = n
    binary = ''
    stack = []
    sub_char = ''
    while a != 0:
        binary = str(a % k) + binary
        a = a // k
    for i in range(len(binary)):
        if binary[i] == "0":
            cnt = 0
            if sub_char:
                for i, c in enumerate(sub_char):
                    cnt += 10 ** (len(sub_char) - (i + 1)) * int(c)
                if cnt != 1:
                    stack.append(cnt)
                sub_char = ''
        else:
            sub_char += binary[i]

    if sub_char:
        cnt = 0
        for i, c in enumerate(sub_char):
            cnt += 10 ** (len(sub_char) - (i + 1)) * int(c)
        stack.append(cnt)
        answer = 0

    while stack:
        num = stack.pop(0)
        flag = 1
        for i in range(2, math.sqrt(num)):
            if num % i == 0:
                flag = 0
                break
        if flag:
            answer += 1

    return answer

# 런타임 에러 하나와 실패 하나