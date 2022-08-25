N, K = map(int, input().split())
array_A = list(map(int, input().split()))
array_B = list(map(int, input().split()))
array_A = sorted(array_A)
array_B = sorted(array_B, reverse=True)
# A 오름차순 B 내림차순
for k in range(K):
    if array_A[k] < array_B[k]:
        array_A[k], array_B[k] = array_B[k], array_A[k]
    else : break
print(sum(array_A))