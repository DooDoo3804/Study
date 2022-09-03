N = int(input())
k_list = list(map(int, input().split()))
d = [0]*100

d[0] = k_list[0]
d[1] = max(k_list[0], k_list[1])
for n in range(2, len(k_list)):
    d[n] = max(k_list[n-1], k_list[n-2]+k_list[n])
print(d[N-1])