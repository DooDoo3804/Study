n, k = map(int, input().split())
check_list = [0 for _ in range(n)]
num_list = [i for i in range(1, n+1)]
result = []
index = 0
count = 0
while 0 in check_list:
    if check_list[index] == 0:
        count += 1
        if count == k:
            result.append(num_list[index])
            check_list[index] = 1
            count = 0
    index += 1
    if index == n:
        index = 0
print("<", end="")
for i, num in enumerate(result):
    if i == n-1 :
        print(num, end="")
    else:
        print(num, end=", ")
print(">")