import sys
num = int(sys.stdin.readline())
count5 = num//5
count3 = 0
while count5 >= 0:
    if (num-count5*5) % 3 == 0:
        count3 = (num-count5*5) // 3
        break
    else:
        count5 -= 1
if count5 == -1:
    print(-1)
else:
    print(count5 + count3)
