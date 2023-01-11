class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        """
            log를 앞 부분을 짤라 이후를 숫자인지, 문자인지 확인하여 각가 나눠서 담는다
            sort를 맨 앞자리와 그 뒷자리로 나눠서 분류를 해준다
        """
        digits, letters = [], []
        for log in logs:
            if log.split()[1].isdigit():
                digits.append(log)
            else:
                letters.append(log)
        letters.sort(key=lambda x: (x.split()[1:], x.split()[0]))
        return letters + digits