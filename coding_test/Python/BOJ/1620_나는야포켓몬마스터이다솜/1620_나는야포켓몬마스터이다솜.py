import sys

n, m = map(int, sys.stdin.readline().strip().split())
num_arr = ["1", "2", "3", "4", "5" ,"6" ,"7", "8", "9", "0"]
arr =  []

for _ in range(n):
    input = str(sys.stdin.readline().strip())
    arr.append(input)

for _ in range(m):
    input_str = str(sys.stdin.readline().strip())
    if (input_str[0] in num_arr):
        print(arr[int(input_str) - 1], end = "\n")
    else :
        print(arr.index(input_str) + 1, end = "\n")
