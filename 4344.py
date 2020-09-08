t = int(input())

for i in range(0, t):
    avg= 0
    u = 0
    l = []
    l = list(map(int, input().split()))
    for j in range(1, l[0]+1) :
        avg += l[j]
    avg /= l[0]
    for j in range(1, l[0]+1) :
        if l[j] > avg:
            u+=1
    print("%0.3f"%(u/l[0]*100),end='')
    print('%')