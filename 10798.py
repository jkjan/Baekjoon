strings = []
for i in range(0, 5):
    strings.append(input())

for j in range(0, 15):
    cnt = 0
    for i in range(0, 5):
        if len(strings[i]) > j:
            print(strings[i][j], end="")
            cnt += 1
    if cnt == 0:
        break


