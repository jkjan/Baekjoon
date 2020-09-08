#include <iostream>
#include <math.h>

#define INF 1000000
using namespace std;

int minOp = INF;
void makeItOne(int X, int cnt);

int main() {
	int X;
	cin >> X;
	makeItOne(X, 0);
	cout << minOp;
	return 0;
}

void makeItOne(int X, int cnt) {
	if (X == 1) {
		minOp = min(cnt, minOp);
		return;
	}

	double num = log(X)/log(3);
	if (num/1.00 == (int)num && minOp > cnt + num) {
		cnt += (int)num;
		minOp = min(cnt, minOp);
		return;
	}

	if (minOp <= cnt - 1) {
		return;
	}

	if (X % 3 == 0) {
		makeItOne(X/3, cnt+1);
	}
	if (X % 2 == 0) {
		makeItOne(X/2, cnt+1);
	}

	makeItOne(X-1, cnt+1);

	return;
}
