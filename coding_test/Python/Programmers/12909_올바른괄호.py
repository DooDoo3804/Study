def solution(s):
    stack = []
    
    for ss in s:
        if ss == "(":
            stack.append(ss)
        elif ss == ")":
            if stack == [] : 
                return False
            elif stack[-1] == "(":
                stack.pop()
            else:
                return False
    if stack != [] :
        return False
    return True