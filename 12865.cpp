#include <iostream>

using namespace std;

int main() {
    int dp[100001][102];
    int W[101];
    int V[101];
    int N, K;

    cin >> N >> K;

    for (int i = 0; i <= K; i++) {
        dp[i][N+1] = 0;
    }

    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    for (int i = N; i >= 1; i--) {
        for (int j = 0; j <= K; j++) {
            if (j < W[i]) {
                dp[j][i] = dp[j][i+1];
                continue;
            }
            dp[j][i] = max(dp[j][i+1], dp[j-W[i]][i+1] + V[i]);
        }
    }
    cout << dp[K][1];
    return 0;
}
