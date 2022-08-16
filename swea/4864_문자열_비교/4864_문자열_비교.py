# 4864_문자열_비교
# 2022-08-16

import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    str1 = str(input())
    str2 = str(input())
    str1_count = str2_count = 0
    for _ in str1:
        str1_count += 1
    for _ in str2:
        str2_count += 1
    result = 0
    for i in range(str2_count-str1_count+1):
        for j in range(str1_count):
            if str1[j] == str2[i+j]:
                count += 1
            else:
                count = 0
                break
        if count == str1_count:
            result = 1
            count = 0
    print('#{} {}' .format(t, result))