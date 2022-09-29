# 4366_정식이의_은행업무
# 2022-09-20
import sys
sys.stdin = open('input.txt', 'r')
T = int(input())
for t in range(1, 1+T):
    n = list(str(input()))
    m = list(str(input()))
    binary = []
    tri = []
    cnt = 0
    for i in range(1, len(n)+1):
        sub_sum = 0
        cnt = 0
        if n[-i] == '0':
            n[-i] = '1'
            for j in range(1, len(n)+1):
                sub_sum += int(n[-j]) * 2**cnt
                cnt += 1
            n[-i] = '0'
        elif n[-i] == '1':
            n[-i] = '0'
            for j in range(1, len(n)+1):
                sub_sum += int(n[-j]) * 2**cnt
                cnt += 1
            n[-i] = '1'
        binary.append(sub_sum)
    for i in range(1, len(m)+1):
        sub_sum = 0
        cnt = 0
        if m[-i] == '0':
            m[-i] = '1'
            for j in range(1, len(m)+1):
                sub_sum += int(m[-j]) * 3**cnt
                cnt += 1
            tri.append(sub_sum)
            m[-i] = '2'
            sub_sum = cnt = 0
            for j in range(1, len(m)+1):
                sub_sum += int(m[-j]) * 3**cnt
                cnt += 1
            tri.append(sub_sum)
            m[-i] = '0'

        elif m[-i] == '1':
            m[-i] = '0'
            for j in range(1, len(m) + 1):
                sub_sum += int(m[-j]) * 3 ** cnt
                cnt += 1
            tri.append(sub_sum)
            m[-i] = '2'
            sub_sum = cnt = 0
            for j in range(1, len(m) + 1):
                sub_sum += int(m[-j]) * 3 ** cnt
                cnt += 1
            tri.append(sub_sum)
            m[-i] = '1'

        elif m[-i] == '2':
            m[-i] = '1'
            for j in range(1, len(m) + 1):
                sub_sum += int(m[-j]) * 3 ** cnt
                cnt += 1
            tri.append(sub_sum)
            m[-i] = '0'
            sub_sum = cnt = 0
            for j in range(1, len(m) + 1):
                sub_sum += int(m[-j]) * 3 ** cnt
                cnt += 1
            tri.append(sub_sum)
            m[-i] = '2'
    for num in binary:
        if num in tri:
            result = num
    print('#{} {}' .format(t, result))