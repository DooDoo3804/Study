class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        memoi = 0
        result = []
        for i, num in enumerate(nums):
            memoi = target - num
            if memoi in nums[i::]:
                for j in range(i+1, len(nums)):
                    if memoi == nums[j]:
                        result.append(i)
                        result.append(j)
                        break
            if len(result) == 2:
                break
        return result
"""
    부르트포스로 풀 수 있지만 시간 초과 가능성이 있음
    dict를 이용해서 뺀 나머지 값이 있는지 확인하는 방법도 가능
"""

"""
    memoi = 0
    result = []
    for i, num in enumerate(nums):
        memoi = target - num
        if memoi in nums[i+1::]:
            result = [i, nums[i+1::].index(memoi)+i+1]
            break
    return result
    위와 같이 풀면 좀 더 빠르고 짧게 작성이 가능하다
"""