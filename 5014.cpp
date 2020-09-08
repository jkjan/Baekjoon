#include <iostream>
#include <vector>
#include <queue>
#define MAX_FLOOR 1000000 + 1
#define INF MAX_FLOOR
using namespace std;
int F, S, G, U, D;
vector<int> graph[MAX_FLOOR];
bool connected[MAX_FLOOR] = {false, };

void makeGraph(int now);
int bfs(int start);

int main() {
    scanf(" %d %d %d %d %d", &F, &S, &G, &U, &D);
    if (S == G) {
        printf("0");
        return 0;
    }
    makeGraph(S);
//    for (int i = 1; i <= F; i++) {
//        printf("%d : ", i);
//        for (auto g : graph[i]) {
//            printf("%d ", g);
//        }
//        printf("\n");
//    }
    int buttons = bfs(S);
    if (buttons == INF)
        printf("use the stairs");
    else
        printf("%d", buttons);

    return 0;
}

void makeGraph(int now) {
    if (now > F || now == G || connected[now])
        return;
    connected[now] = true;
    int up = now + U;
    int down = now - D;

    if (up <= F && U != 0) {
        graph[now].push_back(up);
        makeGraph(up);
    }
    if (down >= 1 && D != 0) {
        graph[now].push_back(down);
        makeGraph(down);
    }
}

int bfs(int start) {
    queue<int> willVisit;
    bool visited[MAX_FLOOR] = {false, };
    willVisit.push(start);
    int dist[MAX_FLOOR];
    fill(dist, dist + MAX_FLOOR, INF);
    dist[start] = 0;
    visited[start] = true;
    bool flag = false;

    while (!willVisit.empty()) {
        if (flag)
            break;
        int nowVisit = willVisit.front();
        willVisit.pop();
        for (auto g : graph[nowVisit]) {
            if (!visited[g]) {
                visited[g] = true;
                willVisit.push(g);
                dist[g] = dist[nowVisit] + 1;
                if (g == G) {
                    flag = true;
                    break;
                }
            }
        }
    }

    return dist[G];
}