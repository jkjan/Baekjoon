#include <iostream>
using namespace std;

int main() {
	int N, K;
	int i;
	int coins[10];
	int cnt = 0;
	int addCnt;
	cin >> N >> K;
	for (i = 0; i < N; i++) {
		cin >> coins[N-i-1];
	}
	i = 0;
	while (0 < K) {
		if (coins[i] <= K) {
			addCnt = K/coins[i];
			cnt += addCnt;
			K -= addCnt * coins[i];
		}
		i++;
	}

	cout << cnt;

	return 0;
}
