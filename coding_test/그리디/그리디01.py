n, m, k = map(int, input().split())
n_data = list(input().split())
n_data.sort()
num1 = int(n_data[-1])
num2 = int(n_data[-2])
max_list = 0
max_list += (m // (k+1)) * (num1*k + num2)
max_list += (m % (k+1)) * num1
print(max_list)