import sys
input = int(sys.stdin.readline().strip())
ans_list = [0, 0, 1]
for i in range(3, input + 1):
    ans_list.append(ans_list[i-1] + ans_list[i-2] * 2)
print(ans_list[input])
