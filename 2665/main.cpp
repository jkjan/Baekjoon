#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_SIZE 51
using namespace std;

int N;
char board[MAX_SIZE][MAX_SIZE];

typedef struct pos {
    int y, x;
} pos;
typedef struct node {
    pos p;
    int changed;
} node;
pos operator+(pos a, pos b) {
    return {a.y + b.y, a.x + b.x};
}
inline bool isValid(pos p) {
    return (1 <= p.y && p.y <= N) && (1 <= p.x && p.x <= N);
}

void input() {
    scanf(" %d", &N);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf(" %c", board[i]+ j);
        }
    }
}

int bfs() {
    pos deltas[] = {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };
    queue<node> willVisit;
    bool visited[50 * 50][MAX_SIZE][MAX_SIZE] = {false, };
    vector<int> cand;
    willVisit.push({1, 1});
    visited[0][1][1] = true;
    while (!willVisit.empty()) {
        node nowVisit = willVisit.front();
        willVisit.pop();

        if (nowVisit.changed >= N * N - 1)
            break;

        if (nowVisit.p.y == N && nowVisit.p.x == N) {
            cand.push_back(nowVisit.changed);
        }

        for (auto d : deltas) {
            pos adj = nowVisit.p + d;
            if (isValid(adj)) {
                int changed = nowVisit.changed;
                if (board[adj.y][adj.x] == '0') {
                    changed++;
                }
                if (!visited[changed][adj.y][adj.x]) {
                    visited[changed][adj.y][adj.x] = true;
                    willVisit.push({adj, changed});
                }
            }
        }
    }
    sort(cand.begin(), cand.end());
    return cand.front();
}

int main() {
    input();
    printf("%d", bfs());
    return 0;
}
