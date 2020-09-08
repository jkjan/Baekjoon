first, second = -1, -1
arr = list(map(int, input().split()))
for elem in arr:
    if first < elem:
        second = first
        first = elem
    elif second < elem:
        second = elem
print(second)