y = 1
a, b, c = input().split()
a = int(a)
b = int(b)
c = int(c)

a15 = []
b28 = {}
c19 = []

i = 0

while True :
    b28[int(i*28+b)] = 0

    if (int(i*19 + c)) in b28 :
        b28[int(i*19 + c)] += 1
        
    if (int(i*15 + a)) in b28 :
        b28[int(i*15 + a)] += 1

        if b28[int(i*15 + a)] == 2:
            break
    
    i += 1

print(i*15+a)