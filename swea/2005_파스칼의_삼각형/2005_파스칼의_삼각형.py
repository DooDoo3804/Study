# 2005_파스칼의 삼각형
# 2022-08-17
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    pas_list = []
    N = int(input())
    for i in range(1, N+1):
        if i == 1:
            pas_list.append([1])
        else:
            temp = [0]*(i)
            for number in range(0, i):
                if number == 0:
                    temp[0] = 1
                elif number == i-1:
                    temp[-1] = 1
                else :
                    temp[number] = pas_list[i-2][number-1]+pas_list[i-2][number]
            pas_list.append(temp)
    print('#{}'.format(t))
    for in_list in pas_list:
        print(*in_list)