#include <iostream>
using namespace std;

int reverse(int);
int getMaxScore();

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << getMaxScore() << endl;
    }
    return 0;
}

int getMaxScore() {
    int dp[3][100001];
    int stickers[3][100001];
    int n;
    cin >> n;

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> stickers[i][j];
        }
    }

    dp[1][1] = stickers[1][1];
    dp[2][1] = stickers[2][1];
    dp[1][2] = stickers[2][1] + stickers[1][2];
    dp[2][2] = stickers[1][1] + stickers[2][2];
    dp[1][3] = max(dp[2][2], dp[2][1]) + stickers[1][3];
    dp[2][3] = max(dp[1][2], dp[1][1]) + stickers[2][3];
    int maxScore = 0;
    int temp[] = {dp[1][1], dp[2][1], dp[1][2], dp[2][2], dp[1][3], dp[2][3]};
    for (int i : temp) {
        maxScore = max(maxScore, i);
    }
    for (int i = 4; i <= n; i++) {
        for (int j = 1; j <=2; j++) {
            int target = reverse(j);
            dp[j][i] = max(dp[j][i-2] + stickers[target][i-1],
                           max(dp[j][i-3] + stickers[target][i-1],
                           dp[target][i-2])) + stickers[j][i];
            maxScore = max(maxScore, dp[j][i]);
        }
    }
    return maxScore;
}

int reverse(int index) {
    return (index == 2 ? 1 : 2);
}