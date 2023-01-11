
import sys
sys.stdin = open('input.txt', 'r')

def binary(num, l, m, r):
    global be_right, be_left
    if a_list[m] == num:
        return 1
    elif num in a_list[l:m]:
        if be_left == False:
            be_left = True
            be_right = False
            l = l
            r = m-1
            m = (l+r) // 2
            return binary(num, l, m, r)
        else:
            return 0

    elif num in a_list[m+1:r+1]:
        if be_right == False:
            be_left = False
            be_right = True
            l = m+1
            r = r
            m = (l+r) // 2
            return binary(num, l, m, r)
        else:
            return 0
    else:
        return 0

T = int(input())
for t in range(1, 1+T):
    n, m = map(int, input().split())
    a_list = list(map(int, input().split()))
    a_list = sorted(a_list)
    b_list = list(map(int, input().split()))
    result = 0
    for num in b_list:
        if num in a_list:
            be_right = be_left = False
            l = 0
            r = n-1
            m = (l+r) // 2
            result += binary(num, l, m, r)
    print('#{} {}' .format(t, result))
