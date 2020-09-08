#include <iostream>
#define MAX_INPUT 10001
using namespace std;

int main() {
	int i, j;
	int N;
	int P[MAX_INPUT];
	int dp[MAX_INPUT];

	cin >> N;
	for (i = 1; i <= N; i++) {
		cin >> P[i];
	}
	dp[0] = 0;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + P[j]);
		}
	}

	cout << dp[N];

	return 0;
}
