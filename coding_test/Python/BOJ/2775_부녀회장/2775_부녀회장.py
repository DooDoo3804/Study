t = int(input())
for _ in range(t):
    k = int(input())
    n = int(input())
    count = [[i for i in range(1, n + 1)] for j in range(k+1)]
    for j in range(k+1):
        if j != 0:
            for i in range(n):
                sum_num = 0
                for m in range(i+1):
                    sum_num += count[j-1][m]
                count[j][i] = sum_num
    print(count[k][n-1])