import sys
sys.stdin = open('input.txt', 'r')

T = int(input())
for t in range(1, T+1):
    A, B = map(str, input().split())
    A_count = B_count = 0
    for _ in A:
        A_count += 1

    for _ in B:
        B_count += 1

    result = count = 0

    while count < A_count:
        word_count = 0
        for b in range(B_count):
            if B[b] == A[count+b]:
                word_count += 1
                if word_count == B_count:
                    result += 1
                    count += B_count
            else :
                result += 1
                count += 1
                break
    print('#{} {}' .format(t, result))