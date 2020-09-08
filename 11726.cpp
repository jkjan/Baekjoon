#include <iostream>
using namespace std;

int n;
int rect[1001];

int tiling(int i);

int main() {
	cin >> n;
	fill_n(rect, 1001, -1);
	cout << tiling(n);
	return 0;
}

int tiling(int i) {
	if (i == 1) {
		rect[i] = 1;
		return 1;
	}
	else if (i == 2) {
		rect[i] = 2;
		return 2;
	}
	else if (rect[i] != -1) {
		return rect[i];
	}
	else {
		rect[i] = (tiling(i-1) + tiling(i-2))%10007;
	}
	return rect[i];
}
