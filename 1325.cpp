#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_NODES 10000 + 1
using namespace std;

int N;
vector<int> graph[MAX_NODES];
typedef pair<int, int> myPair;
myPair groupCnt[MAX_NODES];
void input();
void bfs(int start);

bool compare(myPair a, myPair b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main() {
    input();
    for (int i = 1; i <= N; i++) {
        groupCnt[i] = make_pair(1, i);
    }
    for(int i = 1; i <= N; i++) {
        bfs(i);
    }
    sort(groupCnt+1, groupCnt+N+1, compare);
    int maxCom = groupCnt[1].first;
    int i = 1;
    while (groupCnt[i].first == maxCom) {
        if (i != 1)
            printf(" ");
        printf("%d", groupCnt[i].second);
        i++;
    }

    return 0;
}

void input() {
    int M;
    scanf(" %d %d", &N, &M);
    for (int i = 0 ; i < M; i++) {
        int A, B;
        scanf(" %d %d", &A, &B);
        graph[B].push_back(A);
    }
}

void bfs(int start) {
    queue<int> willVisit;
    bool visited[MAX_NODES] = {false, };
    visited[start] = true;
    willVisit.push(start);

    while (!willVisit.empty()) {
        int nowVisit = willVisit.front();
        willVisit.pop();
        for (auto g : graph[nowVisit]) {
            if (!visited[g]) {
                visited[g] = true;
                willVisit.push(g);
                groupCnt[start].first++;
            }
        }
    }
}
