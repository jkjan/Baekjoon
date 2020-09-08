dp = [[0]*10 for i in range(101)]
dp[1] = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]
n = int(input())
safe = lambda index : 0 if index < 0 or 9 < index else dp[i-1][index]
for i in range(2, n+1):
    for j in range(0, 10):
        dp[i][j] = (safe(j-1) + safe(j+1)) % 1000000000
print(sum(dp[n]) % 1000000000)