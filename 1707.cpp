#include <iostream>
#include <set>
#include <queue>
#define MAX_SIZE 20001
using namespace std;

typedef struct node {
    int v;
    bool isOdd;
} node;

void tc();

int main() {
    int K;
    scanf(" %d", &K);
    for (int i = 0; i < K; ++i) {
        tc();
    }
    return 0;
}

int input(set<int>* graph) {
    int V, E, from, to;
    scanf(" %d %d", &V, &E);
    for (int i = 0; i < E; ++i) {
        scanf(" %d %d", &from, &to);
        graph[from].insert(to);
        graph[to].insert(from);
    }
    return V;
}

bool dfs(int v, bool isOdd, bool visited[2][MAX_SIZE], set<int>* graph) {
    visited[isOdd][v] = true;
    for (auto adj : graph[v]) {
        if (visited[isOdd][adj])
            return false;
        else if (!visited[!isOdd][adj]) {
            if (!dfs(adj, !isOdd, visited, graph))
                return false;
        }
    }
    return true;
}

void tc() {
    set<int> graph[MAX_SIZE];
    int V = input(graph);
    bool visited[2][MAX_SIZE] = {false, };
    bool bipartite = true;
    for (int i = 1; i <= V; ++i) {
        if (!visited[0][i] && !visited[1][i]) {
            if (!dfs(i, true, visited, graph)) {
                bipartite = false;
                break;
            }
        }
    }
    printf(bipartite ? "YES\n" : "NO\n");
}
