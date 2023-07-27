def solution(n):
    answer = 0
    ans = [1, 2]
    for i in range(3, n + 1):
        ans.append((ans[-2] + ans[-1]) %  1000000007)
    answer = ans[n-1]
    return answer