import sys

N = int(sys.stdin.readline())
cnt = {}
arr = []
sum = 0
maxA = 0

for i in range(N):
    n = int(sys.stdin.readline())
    arr.append(n)
    cnt[n] = 1 if n not in cnt.keys() else cnt[n] + 1
    sum += n
    maxA = max(maxA, arr[i])

arr = sorted(arr)
sorted_cnt = sorted(cnt.items(), key=lambda x:(x[1], maxA-x[0]), reverse=True)

avg = round(sum/N)
mid = arr[int(N/2)]

if len(sorted_cnt) == 1:
    frq = sorted_cnt[0][0]
else:
    if sorted_cnt[0][1] == sorted_cnt[1][1]:
        frq = sorted_cnt[1][0]
    else:
        frq = sorted_cnt[0][0]

rng = arr[len(arr)-1] - arr[0]

print(avg)  # 산술평균
print(mid)  # 중앙값
print(frq)  # 최빈값
print(rng)  # 범위