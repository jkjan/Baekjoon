A, B = input().split()

for i in range(2, -1, -1):
    if int(A[i]) == int(B[i]):
        continue
    bigger = A if A[i] > B[i] else B
    for j in range(2, -1, -1):
        print(bigger[j], end='')

    break