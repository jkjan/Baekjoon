container = set()

for i in range(10):
    n = int(input())
    container.add(n % 42)

print(len(container))