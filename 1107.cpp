#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char num[7];
int M;
char* itoa(int n) {
	if (n <= 0) {
		num[0] = '0';
		num[1] = 0;
		return num;
	}
	int jari = log10(n);
	int temp = 0;
	num[jari + 1] = 0;
	for (int i = 0; i < jari + 1; i++) {
		temp = (int)pow(10, jari - i);
		num[i] = n / temp + 48;
		n = n % temp;
	}

	return num;
}

int isin(char* num, char* n) {
	int i = 0;
	for (int j = 0; j < M; j++) {
		i = 0;
		while (num[i] != 0) {
			if (num[i++] == n[j]) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int N, i;

	scanf("%d", &N);
	scanf("%d", &M);

	char* brokenChannels = (char*)malloc(sizeof(char)*(M + 1));

	for (i = 0; i < M; i++) {
		std::cin >> brokenChannels[i];
	}
	brokenChannels[i] = 0;

	if (N == 100) {
		printf("%d", 0);
		free(brokenChannels);
		return 0;
	}

	int p = 0;

	while (1) {
		if (abs(100 - N) <= p + strlen(itoa(N))) {
			printf("%d", abs(100 - N));
			free(brokenChannels);
			return 0;
		}

		if (isin(itoa(N - p), brokenChannels) == 0 || isin(itoa(N + p), brokenChannels) == 0) {
			break;
		}

		p++;
	}

	printf("%d", p + strlen(num));
	free(brokenChannels);
	return 0;
}