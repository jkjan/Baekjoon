#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 100001
#define INF 10000 * 100000 + 1
using namespace std;
typedef long long int ll;
int V;
typedef struct edge {
    int node, weight;
} edge;
bool operator<(edge a, edge b) {
    return a.weight > b.weight;
}
vector<edge> graph[MAX_SIZE];
void input();
vector<int> dijkstra(int start);
int getDiameter();

int main() {
    input();
    printf("%d", getDiameter());
    return 0;
}

void inputVertices() {
    int VN, connected, weight;
    bool edge = false;
    scanf(" %d", &VN);
    while (true) {
        if (!edge) {
            scanf(" %d", &connected);
            if (connected == -1)
                break;
        }
        else {
            scanf(" %d", &weight);
            graph[VN].push_back({connected, weight});
        }
        edge = !edge;
    }
}

void input() {
    scanf(" %d", &V);
    for (int i = 0; i < V; ++i)
        inputVertices();
}

edge maxArr(vector<int> arr) {
    int size = arr.size();
    edge ret = {-1, -1};
    for (int i = 1; i <= size; i++) {
        if (arr[i] > ret.weight && arr[i] != INF) {
            ret = {i, arr[i]};
        }
    }
    return ret;
}

vector<int> dijkstra(int start) {
    priority_queue<edge> willVisit;
    vector<int> dist(MAX_SIZE, INF);
    dist[start] = 0;
    willVisit.push({start, 0});
    while (!willVisit.empty()) {
        edge nowVisit = willVisit.top();
        willVisit.pop();
        for (auto adj : graph[nowVisit.node]) {
            ll newDist = dist[nowVisit.node] + adj.weight;
            if (dist[adj.node] > newDist) {
                dist[adj.node] = newDist;
                willVisit.push({adj.node, (int)newDist});
            }
        }
    }
    return dist;
}

int getDiameter() {
    int x = 1;
    auto fromX = dijkstra(x);
    auto y = maxArr(fromX);
    auto fromY = dijkstra(y.node);
    auto z = maxArr(fromY);
    return z.weight;
}