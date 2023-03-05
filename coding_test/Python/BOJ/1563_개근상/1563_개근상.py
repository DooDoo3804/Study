import sys
n = int(sys.stdin.readline())
dp = [[[0 for _ in range(3)] for _ in range(2)] for _ in range(n)]
dp[0][0][0] = dp[0][1][0] = dp[0][0][1] = 1
# dp[O][L][A]
for i in range(1, n):
    dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]
    dp[i][0][1] = dp[i-1][0][0]
    dp[i][0][2] = dp[i-1][0][1]
    dp[i][1][0] = dp[i-1][0][0] + dp[i-1][1][0] + dp[i-1][0][1] + dp[i-1][0][2] + dp[i-1][1][1] + dp[i-1][1][2]
    dp[i][1][1] = dp[i-1][1][0]
    dp[i][1][2] = dp[i-1][1][1]
result = 0
print((sum(dp[n-1][0]) + sum(dp[n-1][1]))%1000000)