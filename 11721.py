a = input()
b = len(a)
for i in range(1, int(b/10)+1) :
	a = a[:(i*10)+i-1] + '\n' + a[(i*10)+i-1:]
print(a)