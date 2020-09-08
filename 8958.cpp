#include <iostream>
#include <cstring>
using namespace std;

int getScore(char*, int);

int main() {
	int N, len;
	char result[81];
	int i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> result;
		len = strlen(result);
		cout << getScore(result, len) << '\n';
	}

	return 0;
}

int getScore(char* result, int len) {
	int i;
	int score = 0;
	int prob = 0;
	for (i = 0; i < len; i++) {
		if (result[i] == 'O') {
			prob++;
			score += prob;
		}
		else {
			prob = 0;
		}
	}
	return score;
}