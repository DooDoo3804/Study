k, n = map(int, input().split())

lan_list = []
for _ in range(k):
    lan_list.append(int(input()))

start = 1
end = max(lan_list)
while start <= end:
    mid = (start + end) // 2
    cnt = 0
    for l in lan_list:
        cnt += l // mid
    if cnt >= n:
        start = mid + 1
    else :
        end = mid - 1

print(end)