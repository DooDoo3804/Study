n = int(input())
n_list = set(map(int, input().split()))
m = int(input())
check_list = list(map(int, input().split()))
for c in check_list:
    print(1) if c in n_list else print(0)