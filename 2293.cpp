#include <iostream>
#define MAX_COIN 101
#define MAX_VALUE 10001

using namespace std;

void input(int* n, int* k, int* coin);

int main() {
    int dp[2][MAX_VALUE];
    int n, k;
    int coin[MAX_COIN];
    bool up = false;
    input(&n, &k, coin);
    fill(&dp[0][0], &dp[1][MAX_VALUE], 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
//            printf("%d까지로 %d 가능???\n", i, j);
            dp[up][j] = 0;
            if (j % coin[i] == 0) {
                dp[up][j]++;
//                printf("%d만으로 %d 가능\n", i, j);
            }
            for(int l = j; l >= 1; l-= coin[i]) {
                dp[up][j] += dp[!up][l];
//                printf("이전 %d개까지로 %d 되는 %d 경우를 이용 : %d\n", i-1, l, dp[!up][l], dp[up][j]);
            }
        }
        up = !up;
    }

    printf("%d", dp[!(n%2)][k]);

    return 0;
}

void input(int* n, int* k, int* coin) {
    scanf(" %hd %hd", n, k);
    for(int i = 1; i <= *n; i++) {
        scanf(" %hd", coin + i);
    }
}
