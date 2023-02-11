import math
n, m = map(int, input().split())
for num in range(n, m+1):
    if num == 1:
        continue
    for i in range(2, int(math.sqrt(num))+1):
        if num%i == 0:
            break
    else:
        print(num)
