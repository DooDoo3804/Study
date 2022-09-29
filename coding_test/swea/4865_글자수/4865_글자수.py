# 4865_글자수
# 2022-08-16
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    str1 = list(input())
    str2 = list(input())
    str1_dict = {i: 0 for i in str1}
    for i in str2:
        if i in str1_dict:
            str1_dict[i] += 1
    result = 0
    for j in str1_dict.values():
        if j > result:
            result = j
    print('#{} {}' .format(t, result))
    print(str1_dict)