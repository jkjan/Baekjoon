kg= int(input())
bag5 = 0
bag3 = 0

while kg>=3 :
	if (kg%5 == 0):
		bag5 = int(kg/5)
		break

	kg = kg-3
	bag3 += 1
	

if (kg != 0) and kg<3:
	print(-1)
else:
	print(bag3+bag5)