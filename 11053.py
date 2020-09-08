dp = [1] * 1001
N = int(input())
A = [0] + list(map(int, input().split()))

maxLen = 1

for i in range(2, N+1):
    for j in range(1, i):
        if A[i] > A[j]:
            if dp[i] < dp[j] + 1:
                dp[i] = dp[j] + 1
                maxLen = max(maxLen, dp[i])

print(maxLen)