# 5185_이진수
# 2022-09-20

import sys
sys.stdin = open('input.txt', 'r')
def binary(num):
    sub_result = ''
    cont = {
        'A' : '1010',
        'B' : '1011',
        'C' : '1100',
        'D' : '1101',
        'E' : '1110',
        'F' : '1111',
    }
    if num.isnumeric():
        for i in range(3, -1, -1):
            sub_result += '1' if int(num) & (1<<i) else '0'
    else :
        sub_result = cont[num]
    return sub_result

T = int(input())
for t in range(1, 1+T):
    l, chars = map(str, input().split())
    result = ''
    for j in range(int(l)):
        result += binary(chars[j])
    print('#{} {}' .format(t, result))
