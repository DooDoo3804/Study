def solution(n):
    first_num = 0
    next_num = 1
    answer = 0
    for a in range(2, n + 1):
        answer = (first_num + next_num) % 1234567
        first_num = next_num
        next_num = answer
    return answer