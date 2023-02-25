n = int(input())
count = 1
i = 0
while count < n:
    count += 6 * (i)
    i += 1
if n == 1:
    print(1)
else:
    print(i)