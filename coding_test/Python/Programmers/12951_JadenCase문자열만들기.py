def solution(s):
    answer = ''
    
    for ss in s:
        if answer == '':
            answer += ss.upper()
        else:
            if answer[-1] == " ":
                answer += ss.upper()
            else:
                answer += ss.lower()
    return answer