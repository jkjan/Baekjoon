#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 50
#define MAX_NODES 50 * 50
#define INF 50 - 1 + 50 - 1 + 1

using namespace std;

void input();

int R, C;
bool map[MAX_SIZE][MAX_SIZE];
vector<int> graph[MAX_NODES];
int getMaxDist();

int main() {
    input();
    printf("%d", getMaxDist());
    return 0;
}

int indexToNode(int i, int j) {
    return i*C + j;
}

void connect(int i, int j, bool isI) {
    int criterion = isI ? i : j;
    int thatI = i - isI;
    int thatJ = j - !isI;
    if (criterion > 0) {
        if (map[thatI][thatJ]) {
            int thisNode = indexToNode(i, j);
            int thatNode = indexToNode(thatI, thatJ);
            graph[thisNode].push_back(thatNode);
            graph[thatNode].push_back(thisNode);
        }
    }
    if (isI) {
        connect(i, j, false);
        return;
    }
}

void input() {
    scanf(" %d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char temp;
            scanf(" %c", &temp);
            map[i][j] = temp != 'W';

            if (temp == 'L') {
                connect(i, j, true);
            }

        }
        getchar();
    }
}

void bfs(int *maxDist, int start) {
    queue<int> willVisit;
    int dist[MAX_NODES];
    bool visited[MAX_NODES] = {false, };
    visited[start] = true;
    fill(dist, dist + MAX_NODES, INF);
    dist[start] = 0;
    willVisit.push(start);

    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();
        willVisit.pop();
        for (auto g : graph[nowVisit]) {
            if (!visited[g]) {
                visited[g] = true;
                willVisit.push(g);
                dist[g] = dist[nowVisit] + 1;
                *maxDist = max(*maxDist, dist[g]);
            }
        }
    }
}

int getMaxDist() {
    int maxDist = 1;
    for (int i = 0; i < R*C; i++) {
        bfs(&maxDist, i);
    }
    return maxDist;
}