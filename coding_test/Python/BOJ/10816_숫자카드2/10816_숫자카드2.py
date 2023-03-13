from collections import defaultdict
n = int(input())
num_list = list(map(int, input().split()))
nums = defaultdict(int)
for n in num_list:
    nums[n] += 1
m = int(input())
nums_list = list(map(int, input().split()))
for n in nums_list:
    if nums.get(n):
        print(nums.get(n), end=' ')
    else :
        print(0, end=' ')



