sec = [3, 3, 3,
       4, 4, 4,
       5, 5, 5,
       6, 6, 6,
       7, 7, 7,
       8, 8, 8, 8,
       9, 9, 9,
       10, 10, 10, 10]

def alpha_to_sec(alpha):
    index = ord(alpha)-65
    return sec[index]

word = input()
total = 0
for alpha in word:
    total += alpha_to_sec(alpha)

print(total)

