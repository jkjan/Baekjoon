#include <stdio.h>
#include <string.h>
#define JAVA 0
#define C 1
#define UNKNOWN 2

int main() {
	char var[200];
	scanf("%s", var);
	char changed[200];

	int len = strlen(var);
	int i;
	int lang = UNKNOWN;

	if (var[0] < 97) {
		printf("Error!");
		return 0;
	}

	int index = 0;

	for (i = 0; i < len; i++) {
		if (lang == UNKNOWN) {
			if (var[i] == '_') {
				lang = C;
				if (i < len - 1) {
					if (var[i+1] < 97) { // c인데 _ 다음 글자가 대문자
						printf("Error!");
						return 0;
					}
					else {
						//printf("%c", var[++i] - 32);
						changed[index++] = var[++i] - 32;
						continue;
					}
				}
				else { // _가 맨 마지막에 나옴
					printf("Error!");
					return 0;
				}
			}

			else if (var[i] <= 90) {
				lang = JAVA;
				//printf("_%c", var[i] + 32);
				changed[index++] = '_';
				changed[index++] = var[i] + 32;
				if (i < len - 1) {
					if (var[i + 1] <= 90) {
					//	printf("_");
						changed[index++] = '_';
					}
				}
				continue;
			}

			//printf("%c", var[i]);
			changed[index++] = var[i];
		}

		if (lang == JAVA) {
			if (var[i] == '_') {
				printf("Error!"); //자바인데 _ 등장
				return 0;
			}

			else {
				if (var[i] <= 90)
					var[i] += 32;

				//printf("%c", var[i]);
				changed[index++] = var[i];

				if (i < len - 1) {
					if (var[i + 1] <= 90) {
					//	printf("_");
						changed[index++] = '_';
						continue;
					}
				}
			}
		}

		if (lang == C) {
			if (var[i] == '_') {
				if (i >= len - 1) {
					printf("Error!"); //마지막 글자인데 _
					return 0;
				}

				if (var[++i] < 97) { // c인데 _ 다음 글자가 대문자
					printf("Error!");
					return 0;
				}

				else {
					//printf("%c", var[i] - 32);
					changed[index++] = var[i] - 32;
					continue;
				}
			}

			else if (var[i] <= 90) {
				printf("Error!"); // c인데 대문자
				return 0;
			}

			else {
				//printf("%c", var[i]); //소문자는 그대로 출력
				changed[index++] = var[i];
			}
		}
	}

	changed[index] = NULL;
	printf("%s", changed);
	return 0;
}