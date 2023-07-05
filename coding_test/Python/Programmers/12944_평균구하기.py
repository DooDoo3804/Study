def solution(arr):
    count = 0
    n_sum = 0
    for i in arr:
        count += 1
        n_sum += i
    answer = n_sum/count

    return answer