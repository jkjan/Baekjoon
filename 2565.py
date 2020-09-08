dp = [1] * 101
line = [(0, 0)]
N = int(input())

for i in range(1, N+1):
    A, B = map(int, input().split())
    line.append((A, B))

line = (sorted(line, key=lambda left : left[0]))

maxLen = 1

for i in range(2, N+1):
    for j in range(1, i):
        if line[i][1] > line[j][1]:
            if dp[i] < dp[j] + 1:
                dp[i] = dp[j] + 1
                maxLen = max(maxLen, dp[i])
print(N-maxLen)