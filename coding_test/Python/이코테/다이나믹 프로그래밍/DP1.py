T = int(input())
d = [0] *3001
for i in range(2, T+1):
    d[i] = d[i-1] + 1
    # 1을 빼는 경우

    # 아래는 1을 빼는 경우보다 2,3,5로 나누는 경우 더 적게 든다면 그걸로 대체
    # 계속 반복
    if i % 2 == 0:
        d[i] = min(d[i], d[i//2]+1)
    elif i % 3 == 0:
        d[i] = min(d[i], d[i // 3] + 1)
    elif i % 5 == 0:
        d[i] = min(d[i], d[i // 5] + 1)

print(d[T])