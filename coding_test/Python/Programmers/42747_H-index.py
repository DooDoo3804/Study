def solution(citations):
    answer = 0
    citations.sort()
    h_index = 0
    for a in range(citations[-1] + 1):
        sub_sum = len(citations)
        for a in citations:
            if a >= h_index: 
                break
            else:
                sub_sum -= 1
        if sub_sum >= h_index:
            answer = h_index
        else:
             break   
        h_index += 1
    return answer