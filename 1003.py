def fibonacci(n) :
    i = 0
    j = 1

    while n > 0 :
        i += j
        j = i - j
        n -= 1

    return i, j

T = int(input())
for i in range(0, T) :
    temp = int(input())
    a, b = fibonacci(temp)
    print(b, a)