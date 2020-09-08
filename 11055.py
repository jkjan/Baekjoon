dp = [0] * 1001
N = int(input())
A = [0] + list(map(int, input().split()))

dp[1] = A[1]

for i in range(2, N+1):
    dp[i] = A[i]
    for j in range(1, i):
        if A[i] > A[j]:
            if dp[i] < dp[j] + A[i]:
                dp[i] = (dp[j] + A[i])

print(max(dp))