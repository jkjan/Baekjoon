import sys

a = int(input())
for i in range(0, a):
	b, c= sys.stdin.readline().split()
	b = int(b)
	c = int(c)
	print(b+c)