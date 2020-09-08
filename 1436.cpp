#include <stdio.h>
#include <math.h>

int origin(int series);

int well(int series) {
	//int series; //입력받을 값
	//scanf("%d", &series);
	int film = 6;
	int singularity = 0;
	int singularity_point = 0;
	int in_a_zone = 0;
	bool six = true; //true -> 10, false -> 9
	int sixdigit = -1;
	int nosix = 0;
	int decimal = 1;

	if (series <= 6) {
		switch (series) {
		case 1:
			printf("%d", 666);
			return 0;
		case 2:
			printf("%d", 1666);
			return 0;
		case 3:
			printf("%d", 2666);
			return 0;
		case 4:
			printf("%d", 3666);
			return 0;
		case 5:
			printf("%d", 4666);
			return 0;
		case 6:
			printf("%d", 5666);
			return 0;
		default:
			break;
		}
	}

	while (film < series) {
		if (in_a_zone) {

		}

		if (six) {
			film += 10;
			sixdigit++;
		}
		else {
			film += 9;
			nosix++;
			singularity_point = (film - (1 + 9 * nosix));
			if ((singularity_point % 100 == 65) && film < series) {
			//	printf(" 여기!!! %d %d %d ", film, nosix, ((film - (1 + 9 * nosix))));
				decimal = ((singularity_point / 100) % 10 == 6) ? 2 : 1;
				//if (decimal > 1)
				//	printf("1000  ");
				//if (singularity != 0) {

				for (int i = 1; i <= decimal; i++) {
					series -= 9 * (int)pow(10, i);
				}

				//series -= 9 * (int)pow(10, decimal);
				//

				//printf("%d 666\n\n", film - (1 + 9 * nosix));
				singularity++;
				in_a_zone = 1;
				singularity_point = film;
			}
		}
		six = !six;
	}

	//printf("%d\n", film);
	if (singularity > 0) {
		int temp = series - singularity_point - 1 + 9* (int)pow(10, decimal) + 90*(decimal-1);
		if (temp + 1 <= (int)pow(10, decimal+1)) {
			if (singularity != 1) {
				if (singularity % 10 != 7)
					printf("%d", singularity - 1);
				else if (singularity >= 11)
					printf("%d", (singularity - 1) /10);
				//printf("%d", singularity % 10 != 7 ? singularity - 1 : (singularity - 1) / pow(10, decimal));
			}
			printf("666");
			if (decimal > 1 && temp < 100)
				printf("0");
			if (temp < 10)
				printf("0");
			printf("%d", temp);
			//printf(" 여기 %d  %d", singularity_point, series);
			//return 0;
		}
		else {
			//printf("ㅋㅋ%d %d    ", series - 90 * (singularity-1), series);
			origin(singularity == 1 ? series - 9 * (int)pow(10, decimal) * (singularity-1) : series);
			//return 0;
		}
		//printf("  sd %d", (film - (1 + 9 * nosix)));
		//printf("     ////%d  %d %d %d %d", temp, (int)pow(10, decimal + 1), decimal, singularity_point, series);

		return 0;
	}

	if (!six) {
		if (sixdigit) {
			printf("%d", sixdigit);
		}
		printf("666%d", 9 - (film - series));
	}

	else {  //문제의 부분
		printf("%d666", series - (1 + 9 * nosix));
		
	}
	return 0;
}

int origin(int series) {
	//int series; //입력받을 값
	//scanf("%d", &series);
	int film = 6;

	bool six = true; //true -> 10, false -> 9
	int sixdigit = -1;
	int nosix = 0;

	while (film < series) {
		if (six) {
			film += 10;
			sixdigit++;
		}
		else {
			film += 9;
			nosix++;
		}
		six = !six;
	}

	//printf("%d\n", film);

	if (!six) {
		if (sixdigit) {
			printf("%d", sixdigit);
		}
		printf("666%d", 9 - (film - series));
	}

	else {  //문제의 부분
		printf("%d666", series - (1 + 9 * nosix));

	}
	return 0;
}

int main() {

	/*
	for (int i = 1; i <= 10000; i++) {
		printf("%3d : ", i);
		well(i);
		printf("\n");
	}
	*/
	
	
	int s;
	scanf("%d", &s);
	well(s);
	

	return 0;
}