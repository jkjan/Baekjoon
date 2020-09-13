#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_SIZE 51
using namespace std;

int N;
char board[MAX_SIZE][MAX_SIZE];

void input();
int bfs();

int main() {
    input();
    printf("%d", bfs());
    return 0;
}

// 현 위치
typedef struct pos {
    int y, x;
} pos;

// bfs 에서의 노드로, 현 위치와 현재까지 몇 개의 칸을 바꿨는지
typedef struct node {
    pos p;
    int changed;
} node;

// bfs 시 인접 노드를 살피기 위함
pos operator+(pos a, pos b) {
    return {a.y + b.y, a.x + b.x};
}

// 계산된 위치가 유효한지 체크
inline bool isValid(pos p) {
    return (1 <= p.y && p.y <= N) && (1 <= p.x && p.x <= N);
}

// 입력 받기
void input() {
    scanf(" %d", &N);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf(" %c", board[i]+ j);
        }
    }
}

// 가능한 경우에 대해서 bfs
int bfs() {
    pos deltas[] = {
            {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };
    queue<node> willVisit;
    // 0 부터 N * N - 2까지, 총 N * N - 1개 공간이 필요함.
    // visited[n][y][x] : n개의 방을 바꾼 상태로 y, x에 도달한 적이 있는지
    bool visited[50 * 50][MAX_SIZE][MAX_SIZE] = {false, };
    vector<int> cand;
    willVisit.push({1, 1});
    visited[0][1][1] = true;
    while (!willVisit.empty()) {
        node nowVisit = willVisit.front();
        willVisit.pop();

        // 바꿀 수 있는 검은 칸 수는 N * N - 2. 이를 넘어서면 종료
        if (nowVisit.changed >= N * N - 1)
            break;

        // 끝방에 도착했다.
        // 그러나 최단 거리가 항상 칸 수 최소로 바꾸는 거리는 아니므로, 후보군에 추가해준다.
        if (nowVisit.p.y == N && nowVisit.p.x == N) {
            cand.push_back(nowVisit.changed);
        }

        for (auto d : deltas) {
            pos adj = nowVisit.p + d;
            if (isValid(adj)) {
                int changed = nowVisit.changed;
                // 도착한 방이 검은 방이라면 changed 를 늘려준다.
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
    // 후보군들 중 가장 작은 값을 반환한다.
    sort(cand.begin(), cand.end());
    return cand.front();
}