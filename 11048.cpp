#include <iostream>
#define MAX_SIZE 1001

int getDp(int dp[][MAX_SIZE]);

int main() {
    int dp[MAX_SIZE][MAX_SIZE] = {0, };
    printf("%d", getDp(dp));
    return 0;
}

int getDp(int dp[][MAX_SIZE]) {
    int N, M, candy;
    scanf(" %d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf(" %d", &candy);
            dp[i][j] = std::max(dp[i-1][j], std::max(dp[i][j-1], dp[i-1][j-1])) + candy;
        }
    }
    return dp[N][M];
}