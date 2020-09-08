#include <iostream>
#define MAX_SIZE 100001
#define INF 1000 * MAX_SIZE
using namespace std;

int tc();

int main() {
    int cnt = 0;
    int ans;
    while ((ans = tc()) != INF) {
        printf("%d. %d\n", ++cnt, ans);
    }
    return 0;
}

bool input(int* N, int graph[MAX_SIZE][3]) {
    scanf(" %d", N);
    if (*N == 0)
        return false;
    for (int i = 1; i <= *N; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf(" %d", graph[i] + j);
        }
    }
    return true;
}

int getDp(int* N, int graph[MAX_SIZE][3]) {
    int dp[MAX_SIZE][3];
    dp[1][0] = INF;
    dp[1][1] = graph[1][1];
    dp[1][2] = graph[1][1] + graph[1][2];
    for (int i = 2; i <= *N; ++i) {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + graph[i][0];
        dp[i][1] = min(min(dp[i-1][0], dp[i-1][1]), min(dp[i-1][2], dp[i][0])) + graph[i][1];
        dp[i][2] = min(min(dp[i-1][1], dp[i-1][2]), dp[i][1]) + graph[i][2];
    }
    return dp[*N][1];
}

int tc() {
    int N, graph[MAX_SIZE][3];
    if (input(&N, graph))
        return getDp(&N, graph);
    return INF;
}
