num_list = list(map(int, input().split()))
sum_num = 0
while num_list:
    sum_num += (num_list.pop())**2
print(sum_num % 10)