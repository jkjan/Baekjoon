dwarves = []
sum = 0
for i in range(9):
    dwarves.append(int(input()))
    sum += dwarves[i]
sum -= 100
flag = False
for i in range(9):
    for j in range(i+1, 9):
        if dwarves[i] + dwarves[j] == sum:
            dwarves[i] = dwarves[j] = 0
            flag = True
            break
        if flag:
            break
for i in range(9):
    if dwarves[i] != 0:
        print(dwarves[i])