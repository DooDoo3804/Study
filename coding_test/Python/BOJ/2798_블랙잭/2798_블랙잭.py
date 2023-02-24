import sys
n, m = map(int, input().split())
num_list = list(input().split())
max_sum = 0
for i in range(n-2):
    for j in range(i+1, n-1):
        for k in range(j+1, n):
            sum_nums = int(num_list[i]) + int(num_list[j]) + int(num_list[k])
            if max_sum < sum_nums <= m:
                max_sum = sum_nums
print(max_sum)