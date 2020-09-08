#include <iostream>
#include <queue>
#include <vector>
#define MAX_NODES 100 * 100

using namespace std;
typedef struct field {
    int height;
    bool flooded;
} field;

int input(vector<int> *graph, field region[MAX_NODES]);
vector<int> flood(field region[MAX_NODES], int rain);
int indexToNum(int i, int j);
int countSafeZone(int rain, field region[MAX_NODES], vector<int> *graph);

int N;

int main() {
    field region[MAX_NODES];
    vector<int> graph[MAX_NODES];

    int maxHeight = input(graph, region);

    int maxSafeZone = 1;
    for (int i = 0; i <= maxHeight-1; i++) {
        maxSafeZone = max(countSafeZone(i, region, graph), maxSafeZone);
    }

    printf("%d", maxSafeZone);

    return 0;
}

int indexToNum(int i, int j) {
    return i * N + j;
}

void connect(vector<int> *graph, int i, int j, bool isI) {
    if ((isI ? i : j) < N-1) {
        int A = indexToNum(i, j);
        int B = indexToNum(i+isI, j+!isI);
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    if (isI) {
        connect(graph, i, j, false);
        return;
    }
}

int input(vector<int> *graph, field region[MAX_NODES]) {
    int maxHeight = 0;
    scanf(" %d", &N);
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int height;
            int nodeNum = indexToNum(i, j);
            scanf(" %d", &height);
            maxHeight = max(maxHeight, height);
            region[nodeNum] = {height, false};
            connect(graph, i, j, true);
        }
    }
    return maxHeight;
}

vector<int> flood(field region[MAX_NODES], int rain) {
    vector<int> changed;
   for (int i = 0; i < N; i++) {
       for (int j = 0; j < N; j++) {
           int nodeNum = indexToNum(i, j);
           if (region[nodeNum].height <= rain) {
               region[nodeNum].flooded = true;
               changed.push_back(nodeNum);
           }
       }
   }
   return changed;
}

void restore(vector<int>* changed, field region[MAX_NODES]) {
    for (auto c : *changed) {
        region[c].flooded = false;
    }
}

void bfs(bool *visited, int start, field region[MAX_NODES], vector<int> *graph) {
    queue<int> willVisit;
    willVisit.push(start);
    visited[start] = true;

    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();
        willVisit.pop();
        for (auto adj : graph[nowVisit]) {
            if (!visited[adj] && !region[adj].flooded) {
                visited[adj] = true;
                willVisit.push(adj);
            }
        }
    }
}

int countSafeZone(int rain, field region[MAX_NODES], vector<int> *graph) {
    vector<int> changed = flood(region, rain);
    bool visited[MAX_NODES] = {false, };
    int safeZone = 0;

    if (changed.size() == N*N)
        return 0;
    else if (changed.size() == N*N-1 || changed.size() == 1)
        return 1;

    for(int i = 0; i < N*N; i++) {
        if (!visited[i] && !region[i].flooded) {
            bfs(visited, i, region, graph);
            safeZone++;
//            printf("\n");
        }
    }
    restore(&changed, region);

    return safeZone;
}