dp = [0] * 5001
code = 's' + input()

if code[1] != '0':          # 첫글자가 0이면 판단하지 않음
    dp[0] = dp[1] = 1

    for i in range(2, len(code)):
        if code[i] != '0':  # 알파벳 한 글자로 해석 가능하다면
            dp[i] = dp[i-1]

        if 10 <= int(code[i-1:i+1]) <= 26:
            dp[i] += dp[i-2]  # 끝 두 자리가 10 ~ 26
            dp[i] %= 1000000

        elif code[i] == '0':  # 끝이 만일 10 도 20 도 아니라면
            dp[i] = 0
            break             # 해독 불가 판정, 판단 중지

print(dp[len(code)-1])