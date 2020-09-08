inc = [1] * 1001
dec = [1] * 1001
N = int(input())
A = [0] + list(map(int, input().split()))

maxLen = 1

for i in range(1, N+1):
    for j in range(1, i):
        if A[j] < A[i]:
            if inc[i] < inc[j] + 1:
                inc[i] = inc[j] + 1

for i in range(N, 0, -1):
    for l in range(N, i, -1):
        if A[l] < A[i]:
            if dec[i] < dec[l] + 1:
                dec[i] = dec[l] + 1

for i in range(1, N+1):
    maxLen = max(maxLen, inc[i] + dec[i])

print(maxLen - 1)