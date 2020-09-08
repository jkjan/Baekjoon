N = int(input())

def print_star(num):
    blank = N - num
    print(' ' * blank, end='')
    print('*' * (2 * num - 1), end='')
    print()

num = N
flag = -1

while num <= N:
    print_star(num)
    if num == 1:
        flag = 1
    num += flag * 1