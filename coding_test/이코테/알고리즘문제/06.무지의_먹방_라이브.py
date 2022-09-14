def solution(food_times, k):
    answer = 0
    cnt = 0
    idx = 0
    while cnt != k :
        if food_times[idx] == 0:
            idx += 1
            continue
        else:
            food_times[idx] -= 1
        idx += 1
        cnt += 1
        if idx == len(food_times):
            idx = 0
    answer = idx+1
    return answer
# 테케 절반통과
# 효율성 통과 못함