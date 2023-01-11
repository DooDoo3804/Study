# 내림차순 정렬
N = int(input())
num_list = []
for _ in range(N):
    num_list.append(int(input()))
result = sorted(num_list, reverse=True)
print(*result)