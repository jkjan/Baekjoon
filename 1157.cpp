#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str;
	cin >> str;

	int letterCount[26] = {0, };

	for (int i = 0; i < str.length(); i++) {
		if (str[i] > 'Z') {
			letterCount[str[i] - 'a']++;
		}
		else {
			letterCount[str[i] - 'A']++;
		}
	}

	int maxCnt = -1;
	int maxLetter = 0;
	bool dup = false;

	for (int i = 0; i < 26; i++) {
		if (maxCnt < letterCount[i]) {
			maxLetter = i;
			maxCnt = letterCount[i];
			dup = false;
		}

		else if (maxCnt == letterCount[i]) {
			dup = true;
		}
	}

	printf("%c", dup ? '?' : maxLetter + 'A');

	return 0;
}