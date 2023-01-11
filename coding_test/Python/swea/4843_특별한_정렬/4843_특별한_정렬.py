# 4843_특별한_정렬
# 2022-08-11
import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    num_cnt = int(input())
    num_list = list(map(int, input().split()))
    result = []
    count = 0
    for i in range(0, num_cnt):
        for j in range(0, i):
            if num_list[j] > num_list[i]:
                num_list[j], num_list[i] = num_list[i], num_list[j]
    while count < 10:
        count += 1
        if count%2 ==1:
            result.append(num_list[-1])
            num_list = num_list[:-1]
        else :
            result.append(num_list[0])
            num_list = num_list[1:]
    print('#{}' .format(t), *result)