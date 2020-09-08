cnt = 0
bits = 1065233
a = input()
for c in a:
    if bits & (1 << (ord(c) - ord('a'))):
        cnt += 1
print(cnt)