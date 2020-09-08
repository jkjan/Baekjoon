dp = [0]*31
dp[0] = dp[1] = 1

def factorial(n):
    if n <= 1:
        return 1
    elif dp[n] == 0:
        dp[n] = n * factorial(n-1)
    return dp[n]

def combination(size, pick):
    return int(factorial(size)/(factorial(pick) * factorial(size - pick)))

T = int(input())

for i in range(T):
    N, M = map(int, input().split())
    print(combination(M, N))