max_val = 0
max_index = 0

for i in range(1, 10):
    n = int(input())
    if n > max_val:
        max_index = i
        max_val = n

print(max_val)
print(max_index)