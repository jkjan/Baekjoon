#include <iostream>
#define MAX_N 1001
int dp[MAX_N][MAX_N];
int comb(int n, int k);
int main() {
    int N, K;
    scanf(" %d %d", &N, &K);
    printf("%d", comb(N, K));
    return 0;
}

int comb(int n, int k) {
    if (k == 1)
        return n;
    else if (n == k || k == 0)
        return 1;
    else if (dp[n][k] == 0)
        dp[n][k] = (comb(n-1, k-1) + comb(n-1, k)) % 10007;
    return dp[n][k];
}