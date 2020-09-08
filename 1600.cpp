#include <iostream>
#include <queue>
#define MAX_SIZE 200
using namespace std;

typedef struct node {
    int y, x, horsey, dist;
} node;

int K, W, H;
int map[MAX_SIZE][MAX_SIZE];

void input();
int bfs(node start);

int main() {
    input();
    if (W == 1 && H == 1) {
        printf("0");
        return 0;
    }
    printf("%d", bfs({0, 0, 0, 0}));
    return 0;
}

void input() {
    scanf(" %d %d %d", &K, &W, &H);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            scanf(" %d", map[i] + j);
        }
    }
}

bool isValid(node n) {
    return (-1 < n.y && n.y < H) && (-1 < n.x && n.x < W);
}

node operator+(node a, node b) {
    return {a.y + b.y, a.x + b.x, a.horsey, a.dist};
}

int trials(vector<node>* deltas, node nowVisit, bool horsey, bool visited[][MAX_SIZE][MAX_SIZE], queue<node>* willVisit) {
    for (auto d : *deltas) {
        node moved = nowVisit + d;
        if (!isValid(moved))
            continue;
        if (map[moved.y][moved.x])
            continue;
        moved.horsey = nowVisit.horsey + horsey;
        if (visited[moved.horsey][moved.y][moved.x])
            continue;
        moved.dist = nowVisit.dist + 1;
        if (moved.y == H-1 && moved.x == W-1)
            return moved.dist;
        visited[moved.horsey][moved.y][moved.x] = true;
        willVisit->push(moved);
    }
    return 0;
}

int bfs(node start) {
    queue<node> willVisit;
    vector<node>deltas = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    vector<node>horseyDeltas = {
            {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
            {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
    };
    bool visited[31][MAX_SIZE][MAX_SIZE] = {false, };
    visited[start.horsey][start.y][start.x] = true;
    willVisit.push(start);
    while (!willVisit.empty()) {
        node nowVisit = willVisit.front();
        willVisit.pop();
        int ret = trials(&deltas, nowVisit, false, visited, &willVisit);
        if (ret)
            return ret;
        if (nowVisit.horsey < K) {
            ret = trials(&horseyDeltas, nowVisit, true, visited, &willVisit);
            if (ret)
                return ret;
        }
    }
    return -1;
}