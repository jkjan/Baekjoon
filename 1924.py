cal = {1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}

m, d = input().split()
m = int(m)
d = int(d)
t = 0
if (m != 1) :
    for i in range(1, m):
        t += cal[i]
    t+= d
    t = t%7
else:
    t = d%7

if t == 0:
    print('SUN')
elif t == 1:
    print('MON')
elif t == 2:
    print('TUE')
elif t == 3:
    print('WED')
elif t == 4 :
    print('THU')
elif t== 5:
    print('FRI')
elif t == 6:
    print('SAT')