import collections, re
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words = [word for word in re.sub(r'[^\w]', ' ', paragraph).lower().split() if word not in banned]
        counts = collections.Counter(words)
        return counts.most_common(1)[0][0]
"""
    문자열을 치환해 주는 메서드 replace
    `import re`
    `re.sub(정규 표현식, 치환 문자, 대상 문자열)`로 사용
    정규 표현식 - 검색 패턴
        r'[\w]' 단어 단위 (어절)
        ^ : 부정의 not
    치환 문자 - 바꿀 문자
    
    list comprehension을 이용하여 word를 단어 단위로 잘라 문자가 아니면
    ''로 바꾸고 lowercase로 변환하여 저장한다
    counter를 사용하면 단어를 카운트 할 수 있음
    most_common : 최빈 값
"""