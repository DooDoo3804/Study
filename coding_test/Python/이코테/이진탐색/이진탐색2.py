N, M = map(int, input().split())
rc_list = list(map(int, input().split()))
rc_list = sorted(rc_list, reverse=True)
result_len = 0
for j in range(max(rc_list), -1, -1):
    result = 0
    for i in range(N):
        if rc_list[i] >= j:
            result += rc_list[i]-j
        else : break
    if result == M:
        result_len = j
        break
print(result_len)
# 이진 탐색 문제로도 풀이 가능
