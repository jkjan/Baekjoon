numbers = [1 for n in range(0, 10001)]

def d(n):
    if n > 10000 or numbers[n] == 0:
        return
    num = n

    while n > 0:
        num += n % 10
        n = int(n/10)

    if num <= 10000:
        d(num)
        numbers[num] = 0


for i in range(1, 10001):
    d(i)

for i in range(1, 10001):
    if numbers[i] == 1:
        print(i)