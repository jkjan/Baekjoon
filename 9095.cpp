#include <iostream>
using namespace std;

int main() {
	int tc;
	int n;
	int plus[11];
	fill_n(plus, 11, -1);
	plus[1] = 1;
	plus[2] = 2;
	plus[3] = 4;

	cin >> tc;

	for (int j = 0; j < tc; j++) {
		cin >> n;

		for (int i = 4; i <= n; i++) {
			if (plus[i] == -1)
				plus[i] = plus[i-1] + plus[i-2] + plus[i-3];
		}

		cout << plus[n] << endl;
	}

	return 0;
}
