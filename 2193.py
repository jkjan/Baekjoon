dp = [0] * 91
dp[1] = dp[2] = 1
N = int(input())
for i in range(3, N+1):
    dp[i] = dp[i-1] + dp[i-2]
print(dp[N])