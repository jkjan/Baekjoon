n = int(input())
num = [0] + list(map(int, input().split()))
dp = num[:]

if n == 1:
    print(num[1])
else:
    dp[1] = num[1]
    answer = dp[1]
    for i in range(2, n+1):
        if dp[i-1] > 0 and dp[i] + dp[i-1] > 0:
            dp[i] += dp[i-1]
        answer = max(dp[i], answer)
    print(answer)
