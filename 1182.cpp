#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, S;
	int i, j;
	int sum, cnt;
	sum = cnt = 0;
	cin >> N >> S;

	vector <int> seq(N);

	for (i = 0; i < N; i++) {
		cin >> seq[i];
	}

	for (i = 0; i < N; i++) {
		vector <bool> com;
		for (j = 0; j < i; j++) {
			com.push_back(false);
		}
		for (j = 0; j < N-i; j++) {
			com.push_back(true);
		}
		do {
			sum = 0;
			for (j = 0; j < N; j++) {
				if (com[j]) {
					sum+=seq[j];
				}
			}
			if (sum == S) {
				cnt++;
			}
		}while (next_permutation(com.begin(), com.end()));
	}

	cout << cnt;

	return 0;
}