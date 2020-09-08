num = list(map(int, input().split()))
cnt = 0
for n in num:
    cnt += n**2
print(cnt % 10)