class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expands(left, right):
            while left >= 0 and right < len(s) and s[left]==s[right]:
                left -= 1
                right += 1
            return s[left+1 : right]
        result = ''
        if len(s) == 1 or s == s[::-1]:
            return s
        else:
            for i in range(len(s)-1):
                result = max(result, expands(i, i+1), expands(i, i+2), key=len)
            return result
"""
    투 포인터로 확장시키면서 탐색
    DP로도 가능하지만 이는 시간이 오래 걸림
    
    expands 함수는 좌우 한칸씩 벌리면서 같은 문자열이면 계속 확장시킴
    max의 키값을 설정하여 문자열 길이 len을 기준으로 판별
    result를 반환 
"""
