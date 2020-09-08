#include <iostream>
#include <cmath>
#define MAX_SIZE 100001

int getDp(int N);

int main() {
    int N;
    scanf(" %d", &N);
    printf("%d", getDp(N));
    return 0;
}

int getDp(int N) {
    int dp[MAX_SIZE];
    int square;
    for (int i = 0; i <= N; ++i) {
        dp[i] = i;
    }
    for (int i = 4; i <= N; ++i) {
        int temp = (int)sqrt(i);
        temp *= temp;
        if (temp == i) {
            dp[i] = 1;
            continue;
        }
        for (int j = 1; (square = j * j) <= temp; ++j) {
            dp[i] = std::min(dp[i], dp[i - square] + dp[square]);
        }
    }
    return dp[N];
}