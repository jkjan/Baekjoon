dp = [[0]*501 for i in range(0, 501)]
triangle = [0]
n = int(input())
for i in range(0, n) :
    line = [0]
    line += list(map(int, input().split()))
    line.append(0)
    triangle.append(line)

dp[1][1] = triangle[1][1]
for i in range(2, n+1) :
    for j in range(1, i+1) :
        dp[i][j] = triangle[i][j] + max(dp[i-1][j], dp[i-1][j-1])

print(max(dp[n]))