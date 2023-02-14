import math
n = int(input())
num_list = list(map(int, input().split()))
count = 0
for i in num_list:
    if i == 1:
        continue
    for j in range(2, int(math.sqrt(i))+1):
        if i % j == 0:
            break
    else:
        count += 1
print(count)