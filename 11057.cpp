#include <iostream>
#define MAX_SIZE 1001

int getDp(int N);

int main() {
    int N;
    scanf(" %d", &N);
    printf("%d", getDp(N));
    return 0;
}

int getDp(int N) {
    int dp[MAX_SIZE][10] = {0, };
    std::fill(dp[1], &(dp[1][10]), 1);
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007;
            }
        }
    }
    int sum = 0;
    for (auto d : dp[N]) {
        sum += d;
        sum %= 10007;
    }
    return sum;
}