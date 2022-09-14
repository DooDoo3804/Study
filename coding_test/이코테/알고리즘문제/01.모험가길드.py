import sys

n = int(input())
members = list(map(int, input().split()))
members = sorted(members)
count = 0
while members:
    fear = members[-1]
    for _ in range(fear):
        if members == []:
            break
        members.pop(-1)
    count += 1
print(count)