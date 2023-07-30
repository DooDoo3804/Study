def find_max(a, b) :
    return_num = a * b
    while b != 0:
        a, b = b, a % b
    return return_num / a

def solution(arr):
    arr.sort(reverse=True)
    answer = arr[0]
    for i in range(1, len(arr)):
        answer = find_max(answer, arr[i])
    return answer