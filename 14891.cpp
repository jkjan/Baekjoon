#include <iostream>
#include <bitset>
#include <x86intrin.h>
using namespace std;

char gear[4] = {0, };
bool rotated[4];
void rotate(int which, int d);

int main() {
	int k;
	int which, d;
	char bit;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> bit;
			gear[i] += bit == '1' ? true : false;
			if (j < 7)
				gear[i] = gear[i] << 1;
		}
		getchar();
	}

	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> which >> d;
		fill_n(rotated, 4, false);
		rotate(which - 1, d);
	}

	int score = 0;
	int p = 1;

	for (int i = 0; i < 4; i++) {
		if ((gear[i] & 0b10000000) == 0b10000000) {
			score += p;
		}
		p *= 2;
	}

	cout << score;

	return 0;
}

void rotate(int which, int d) {
	if (rotated[which]) {
		return;
	}
	rotated[which] = true;

	if (which < 3) {
		if (!rotated[which+1]) {
			int third = gear[which] & 0b00100000;
			int sixth = gear[which+1] & 0b00000010;
			if ((third == 0) != (sixth == 0)) {
				rotate(which + 1, -d);
			}
		}
	}

	if (which > 0) {
		if (!rotated[which-1]) {
			int sixth = gear[which] & 0b00000010;
			int third = gear[which - 1] & 0b00100000;
			if ((third == 0) != (sixth == 0)) {
				rotate(which - 1, -d);
			}
		}
	}

	if (d == 1) {
		gear[which] = __rorb(gear[which], 1);
	}
	else {
		gear[which] = __rolb(gear[which], 1);
	}
}
