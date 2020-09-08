a = int(input())

l = list(map(int, input().split()))

max = l[0]

for i in range(0, len(l)):
    if l[i] > max:
        max = l[i]

avg = 0

for i in range(0, len(l)):
    avg += l[i]/max*100

avg /= a

print(avg)