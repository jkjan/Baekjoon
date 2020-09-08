#include <iostream>
#include <queue>
#include <vector>
#define INF 100 * 100
#define MAX_SIZE 100
using namespace std;

typedef struct node {
    int y, x, dist;
} node;

int N;
int map[MAX_SIZE][MAX_SIZE];
void input();
int getShortestBridge();

int main() {
    input();
    printf("%d", getShortestBridge());
    return 0;
}

void input() {
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf(" %d", &(map[i][j]));
        }
    }
}

void printMap() {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            printf("%d ", map[k][i]);
        }
        printf("\n");
    }
}

int bfs(deque<node>* willVisit, bool visited[][MAX_SIZE], int num, bool extend) {
    node deltas[] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<node> outerNodes;
    visited[willVisit->front().y][willVisit->front().x] = true;
    while (!willVisit->empty()) {
        node nowVisit = willVisit->front();
        willVisit->pop_front();
        if (!extend)
            map[nowVisit.y][nowVisit.x] = num;
        bool outer = false;
        for (auto d : deltas) {
            node moved = {nowVisit.y + d.y, nowVisit.x + d.x};
            if (!(-1 < moved.y && moved.y < N && -1 < moved.x && moved.x < N))
                continue;
            if (visited[moved.y][moved.x])
                continue;
            moved.dist = nowVisit.dist + 1;

            // 첫번째 bfs 라면 0이 아닐 때만, 두번째라면 무조건 확장
            if ((!extend && map[moved.y][moved.x]) || (extend && map[moved.y][moved.x] != num)) {
                // 다른 섬 발견
                if (extend && (map[moved.y][moved.x] != 0)) {
                    return moved.dist;
                }
                visited[moved.y][moved.x] = true;
                willVisit->push_back(moved);
            }
            else if (!extend && !map[moved.y][moved.x])
                outer = true;
        }

        if (!extend) {
            if (outer) {
                outerNodes.push_back(nowVisit);
            }
        }
    }

    if (!extend) {
        for (auto & o : outerNodes) {
            o.dist = 0;
            willVisit->push_back(o);
        }
    }

    return INF;
}


int getShortestBridge() {
    int island = 1;
    bool visited[MAX_SIZE][MAX_SIZE] = {false, };
    int shortest = INF;
    vector< deque<node> > outerNodes;
    outerNodes.emplace_back();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j] && map[i][j]) {
                outerNodes.emplace_back();
                outerNodes[island].push_back({i, j});
                bfs(&(outerNodes[island]), visited, island, false);
                island++;
            }
        }
    }

    for (int i = 1; i < outerNodes.size(); ++i) {
        bool newVisited[MAX_SIZE][MAX_SIZE] = {false, };
        shortest = min(shortest, bfs(&(outerNodes[i]), newVisited, i, true));
    }

    return shortest - 1;
}