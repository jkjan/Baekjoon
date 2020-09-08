dp = [1, 1, 2, 4] + [0]*64

def fib(n):
    if n <= 3:
        return dp[n]
    elif dp[n] == 0:
        dp[n] = fib(n-4) + fib(n-3) + fib(n-2) + fib(n-1)
    return dp[n]

t = int(input())
for i in range(t):
    print(fib(int(input())))