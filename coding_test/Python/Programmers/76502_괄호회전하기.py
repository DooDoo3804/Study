def solution(s):
    answer = 0
    
    for i in range(len(s)):
        sub_s = s[i + 1::] + s[0:i + 1]
        sub_list = []
        check = True
        for ss in sub_s:
            if ss in ["[" , "(" , "{"]:
                sub_list.append(ss)
            elif sub_list == []:
                check = False
                break
            elif ss == ")":
                if sub_list[-1] == "(":
                    sub_list.pop()
                else:
                    check = False
                    break
            elif ss == "}":
                if sub_list[-1] == "{":
                    sub_list.pop()
                else:
                    check = False
                    break
            elif ss == "]":
                if sub_list[-1] == "[":
                    sub_list.pop()
                else:
                    check = False
                    break
        if sub_list != [] : check = False
        if check : answer += 1
                   
    return answer