dp = [0] * 101
dp[1], dp[2], dp[3], dp[4], dp[5] = 1, 1, 1, 2, 2
def wave(n) :
    if n <= 5 :
        return dp[n]
    elif dp[n] == 0 :
        dp[n] = wave(n-1) + wave(n-5)
    return dp[n]

T = int(input())
for i in range(0, T) :
    print(wave(int(input())))