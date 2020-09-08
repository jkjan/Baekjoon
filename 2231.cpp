#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int N;
	int i, l;
	int candidate = 0;
	int sum;

	cin >> N;

	for (i = 1; i < N; i++) {
		candidate = i;
		sum  = candidate;
		for (l = (int)log10(i); l >= 0; l--) {
			//cout << candidate / (int)pow(10, l) << '\n';
			sum += (candidate / (int)pow(10, l));
			candidate %= (int)pow(10, l);
		}

		//cout << sum ;
		if (sum == N) {
			cout << i;
			return 0;
		}
		//cout << '\n';
	}

	cout << 0;

	return 0;
}