K, N = map(int, input().split())
cables = []
for i in range(K):
    cables.append(int(input()))

high = max(cables)
middle = min(cables)
low = 0
check = {}


def get_sum(cur):
    sum = 0
    for c in cables:
        sum += int(c/cur)
    return sum

def find(high, middle, low):
    if middle in check.keys():
        print(middle)
        return

    sum = get_sum(middle)
    check[middle] = sum

    if sum >= N:
        low = middle
        middle = int((high+middle)/2)
    else:
        high = middle
        middle = int((middle + low)/2)

    find(high, middle, low)


find(high, middle, low)