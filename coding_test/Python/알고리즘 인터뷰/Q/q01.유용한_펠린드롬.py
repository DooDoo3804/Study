class Solution:
    def isPalindrome(self, s: str) -> bool:
        result = []
        r_result = []
        for char in s:
            if char.isalnum():
                result.append(char.lower())
        for i in range(len(s)-1, -1, -1):
            if s[i].isalnum():
                r_result.append(s[i].lower())
        if result == r_result:
            return True
        else:
            return False