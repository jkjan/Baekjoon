#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#define MAX_SIZE 8
using namespace std;

typedef struct trial {
    int level;
    vector<bool> prev;
    deque<int> history;
} trial;

int N, M;
int arr[MAX_SIZE];
void dfs();
bool check[MAX_SIZE];
vector<int> history;
void getSequence(int level);

int main() {
    scanf(" %d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf(" %d", arr + i);
    }

    std::sort(arr, arr+N);
    getSequence(0);
    return 0;
}

void dfs() {
    stack<trial> willVisit;
    willVisit.push({0, vector<bool>(10001, false), deque<int>()});

    while (!willVisit.empty()) {
        trial nowVisit = willVisit.top();
        willVisit.pop();
        if (nowVisit.level == M) {
            while (!nowVisit.history.empty()) {
                printf("%d ", nowVisit.history.front());
                nowVisit.history.pop_front();
            }
            printf("\n");
        }
        else {
            for (int i = N-1; i >= 0; i--) {
                if (!nowVisit.prev[i]) {
                    nowVisit.history.push_back(arr[i]);
                    nowVisit.prev[i] = true;
                    willVisit.push({nowVisit.level+1, nowVisit.prev, nowVisit.history});
                    nowVisit.history.pop_back();
                    nowVisit.prev[i] = false;
                }
            }
        }
    }
}

void getSequence(int level) {
    if (level == M) {
        for (auto h : history) {
            printf("%d ", h);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!check[i]) {
            check[i] = true;
            history.push_back(arr[i]);

            getSequence(level+1);

            check[i] = false;
            history.pop_back();
        }
    }
}