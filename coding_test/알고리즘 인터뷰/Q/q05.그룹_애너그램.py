import collections
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = collections.defaultdict(list)
        for char in strs:
            anagrams[''.join(sorted(char))].append(char)
        return list(anagrams.values())
"""
    defaultdict를 활용
    defaultdict는 없는 값이면 자동적으로 default값을 부여하고 이후 연산진행
"""