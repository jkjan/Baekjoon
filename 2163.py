dp = [[0]*301 for i in range(301)]

def cutChocolate(n, m) :
    if n < m :
        n, m = m, n
    if m == 1 :
        return n - 1
    elif dp[n][m] == 0 :
        half = int(n / 2)
        otherHalf = n - half
        dp[n][m] = cutChocolate(half, m) + cutChocolate(otherHalf, m) + 1
    return dp[n][m]

a, b = map(int, input().split())
print(cutChocolate(a, b))