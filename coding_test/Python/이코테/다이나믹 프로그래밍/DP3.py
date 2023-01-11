N = int(input())
d = [0]*1000
d[0] = 1
d[1] = 3
for i in range(2, N):
    if d[i] == 0:
        d[i] = d[i-1] + 2*d[i-2]
print(d[N-1])