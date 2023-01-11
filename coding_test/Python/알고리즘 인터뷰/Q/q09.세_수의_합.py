from collections import deque
nums = list(map(int, input().split()))

stack = deque()
sub_stack = deque()
sub = 0
for i, n in enumerate(nums):
    sub_stack.append(n)
    for j in range(i + 1, len(nums) - 1):
        sub_stack.append(nums[j])
        if -sum(sub_stack) in nums[j + 1::]:
            sub_stack.append(-sum(sub_stack))
            if sorted(sub_stack) not in stack:
                stack.append(sorted(sub_stack))
            sub_stack.pop()
        sub_stack.pop()
    sub_stack.pop()

print(stack)