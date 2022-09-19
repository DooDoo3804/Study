# 1240_단순_2진_암호코드
# 2022-09-19

import sys
sys.stdin = open('input.txt', 'r')

def find_num(stack):
    """
    숫자 배열을 받아 그에 맞는 해독 값을 반환
    Args:
        stack (str): 7자리 숫자 배열

    Returns:
        int: 숫자 배열에 맞는 해독 값을 반환
             없으면 -1을 반환한다
    """
    nums = {
        '0001101' : 0,
        '0011001' : 1,
        '0010011' : 2,
        '0111101' : 3,
        '0100011' : 4,
        '0110001' : 5,
        '0101111' : 6,
        '0111011' : 7,
        '0110111' : 8,
        '0001011' : 9,
    }
    if str(stack) not in nums:
        return -1
    return nums[stack]

T = int(input())
for t in range(1, 1+T):
    n, m = map(int, input().split())
    stack = []
    flag = False
    for _ in range(n):
        num_list = list(map(int, input()))
        if 1 in num_list and flag == False:
            stack = num_list
            flag = True
    start = 0
    for i, char in enumerate(stack):
        if char == 1:
            start = i - 3
            break
    cnt = 0
    sub_stack = ''
    result = []
    for j in range(0, 4):
        for i in range(start+j, start+j+56+1):
            sub_stack += str(stack[i])
            cnt += 1
            if cnt == 7:
                if find_num(sub_stack) != -1:
                    result.append(find_num(sub_stack))
                    cnt = 0
                    sub_stack = ''
                else:
                    cnt = 0
                    sub_stack = ''
                    break
        check = 0
        for i, v in enumerate(result):
            if i%2 :
                check += v
            else:
                check += v*3
        if check % 10 == 0 and check != 0:
            break
        else:
            result = []
    print('#{} {}' .format(t, sum(result)))
