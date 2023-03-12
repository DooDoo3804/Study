n = int(input())
user_list = []
for i in range(n):
    user_list.append(list(input().split()))
user_list.sort(key=lambda x: int(x[0]))
for u in user_list:
    print(f'{u[0]} {u[1]}')
