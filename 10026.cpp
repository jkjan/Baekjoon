#include <iostream>
#include <queue>
#define MAX_SIZE 100
using namespace std;

int N;
char picture[MAX_SIZE][MAX_SIZE];
int mark[][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
};

typedef struct pos {
    int y, x;
} pos;

int getRegion(bool isBlinded);
void input();

int main() {
    input();
    printf("%d %d", getRegion(false), getRegion(true));

    return 0;
}

void input() {
    scanf(" %d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &(picture[i][j]));
        }
        getchar();
    }
}

bool lookSame(bool isBlinded, char colorA, char colorB) {
    if (colorA == colorB)
        return true;
    else {
        if (!isBlinded)
            return false;
        else {
            if (colorB == 'R')
                swap(colorA, colorB);
            return colorA == 'R' && colorB == 'G';
        }
    }
}

bool isValid(pos index) {
    return
        ((0 <= index.y && index.y < N)
      && (0 <= index.x && index.x < N)
        );
}

void bfs(int startY, int startX, bool visited[][MAX_SIZE], bool isBlinded) {
    queue<pos> willVisit;
    willVisit.push({startY, startX});
    visited[startY][startX] = true;
    char nowColor = picture[startY][startX];

    while (!willVisit.empty()) {
        pos nowVisit = willVisit.front();
        willVisit.pop();

        for (auto & i : mark) {
            pos now = {nowVisit.y + i[0],
                       nowVisit.x + i[1]};

            if (!isValid(now))
                continue;

            if (!visited[now.y][now.x] && lookSame(isBlinded, nowColor, picture[now.y][now.x])) {
                willVisit.push(now);
                visited[now.y][now.x] = true;
            }
        }
    }
}

int getRegion(bool isBlinded) {
    bool visited[MAX_SIZE][MAX_SIZE] = {{false}};
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(i, j, visited, isBlinded);
                cnt++;
            }
        }
    }
    return cnt;
}