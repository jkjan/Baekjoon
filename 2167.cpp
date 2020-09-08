#include <iostream>
#define MAX_SIZE 301

int N, M;
int dp[MAX_SIZE][MAX_SIZE] = {0, };

void input();
int getSum(int i, int j, int x, int y);
void tc();

int main() {
    int K;
    input();
    scanf(" %d", &K);
    for (int k = 0; k < K; ++k) {
        tc();
    }
    return 0;
}

void input() {
    scanf(" %d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            scanf(" %d", dp[i] + j);
            dp[i][j] += (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]);
        }
    }
}

int getSum(int i, int j, int x, int y) {
    return dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1];
}

void tc() {
    int i, j, x, y;
    scanf(" %d %d %d %d", &i, &j, &x, &y);
    printf("%d\n", getSum(i, j, x, y));
}