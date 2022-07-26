n, m = map(int, input().split())
minimum_list = []
for i in range(n):
    num_list = list(input().split())
    minimum_list.append(min(num_list))
print(max(minimum_list))