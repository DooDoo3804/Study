from collections import Counter

n = int(input())
nums_list = []
for _ in range(n):
    nums_list.append(int(input()))
nums_list.sort()

cnt = Counter(nums_list).most_common(2)

print(round(sum(nums_list)/n))
print(nums_list[n//2])
if len(cnt) > 1:
    if cnt[0][1] == cnt[1][1]:
        print(cnt[1][0])
    else:
        print(cnt[0][0])
else:
    print(cnt[0][0])
print(nums_list[-1] - nums_list[0])
