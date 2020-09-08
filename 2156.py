dp = [0] * 10001
n = int(input())
wine = [0]

for i in range(0, n):
    wine.append(int(input()))

if n == 1:
    print(wine[1])
elif n == 2:
    print(wine[1]+wine[2])
else:
    dp[1] = wine[1]
    dp[2] = wine[1] + wine[2]
    dp[3] = max(dp[2], max(wine[1], wine[2]) + wine[3])

    for i in range(4, n + 1):
        dp[i] = max(dp[i-1],
                    max(dp[i - 2] + wine[i],
                        dp[i - 3] + wine[i - 1] + wine[i]))

    print(dp[n])