N = int(input())
answer = []
for _ in range(N):
    a = str(input())
    if a not in answer:
        answer.append(a)
answer.sort(key=lambda x: (len(x), x))
for i in answer:
    print(i)