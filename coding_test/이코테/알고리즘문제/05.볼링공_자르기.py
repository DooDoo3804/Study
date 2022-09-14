n, m = map(int, input().split())
balls = list(map(int, input().split()))
balls.sort()
count = 0
for i, b in enumerate(balls):
    for j in range(i, n):
         if balls[j] != b:
             count += 1
print(count)