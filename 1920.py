N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = list(map(int, input().split()))
A = sorted(A)

def isIn(x, high, low):
    if high >= low:
        return True if A[high] == x else False

    middle = int((high + low)/2)

    if A[middle] > x:
        return isIn(x, high, middle-1)
    elif A[middle] < x:
        return isIn(x, middle+1, low)
    else:
        return True


for b in B:
    print('1' if isIn(b, 0, len(A)-1) else '0')