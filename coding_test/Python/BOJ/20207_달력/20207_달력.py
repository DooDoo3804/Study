import sys
n = int(sys.stdin.readline().strip())
days = []
for _ in range(n):
    a, b = map(int, sys.stdin.readline().split())
    days.append([a, b, (b-a+1)])
days.sort(key=lambda x : x[2], reverse=True)
print(days)