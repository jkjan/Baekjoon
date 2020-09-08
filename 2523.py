def print_star(num):
    print('*' * num)

N = int(input())
num = 1
flag = 1

while num != 0:
    print_star(num)
    if num == N:
        flag = -1
    num += flag * 1