num = list(input())
sum1 = sum2 = 0
for i in range(len(num)):
    if i < len(num)//2:
        sum1 += int(num[i])
    else :
        sum2 += int(num[i])
if sum1 == sum2 :
    print('LUCKY')
else :
    print('READY')