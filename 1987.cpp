#include <iostream>
#include <vector>
#define MAX_SIZE 20 * 20
using namespace std;

int R, C;
bool visited[MAX_SIZE]= {false, };
char board[MAX_SIZE];
vector<int> graph[MAX_SIZE];
bool alpha[26] = {false, };
int answer = 1;

void input();
void dfs(int start, int cnt);

int main() {
    int cnt = 1;
    input();
    alpha[board[0] - 'A'] = true;
    dfs(0, 1);
    printf("%d", answer);

    return 0;
}

void connect(int thisNode, bool isI) {
    int thatNode;
    if (isI) {
        if (thisNode % C == 0)
            return;
        thatNode = thisNode - 1;
    }
    else {
        if (thisNode / C == 0)
            return;
        thatNode = thisNode - C;
    }
    graph[thisNode].push_back(thatNode);
    graph[thatNode].push_back(thisNode);
}

void input() {
    scanf(" %d %d", &R, &C);
    for (int i = 0; i < R*C; i++) {
        scanf(" %c", board + i);
        connect(i, true);
        connect(i, false);

        if ((i+1) % C == 0)
            getchar();
    }
}

void dfs(int start, int cnt) {
    answer = max(answer, cnt);

    for (auto & g : graph[start]) {
        if (!alpha[board[g] - 'A']) {
            alpha[board[g] - 'A'] = true;
            dfs(g, cnt + 1);
            alpha[board[g] - 'A'] = false;
        }
    }
}