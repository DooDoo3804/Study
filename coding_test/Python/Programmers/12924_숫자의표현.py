def solution(n):
    answer = 0
    
    for nn in range(1, n + 1):
        sub_sum = 0
        for nnn in range(nn, n + 1):
            sub_sum += nnn
            if sub_sum == n:
                answer += 1
                break
            elif sub_sum > n:
                break
    return answer