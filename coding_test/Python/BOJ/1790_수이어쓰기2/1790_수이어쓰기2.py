n, k = map(int, input().split())

n_count = 0
count = 0
num = 0
while n_count < k:
    n_count += 10**(count) * (count+1) * 9
    if n_count > k:
        n_count -= 10 ** (count) * (count + 1) * 9
        break
    count += 1


if (k-n_count) % (count+1):
    num = 10**(count) + ((k-n_count) // (count+1))
    if num > n:
        print(-1)
    else: print(str(num)[((k - n_count) % (count + 1))-1])
else:
    num = 10**(count) + ((k-n_count) // (count+1)) -1
    if num > n:
        print(-1)

    else: print(str(num)[-1])