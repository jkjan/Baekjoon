#include <iostream>
#define MAX_SIZE 20
using namespace std;

void input();
void output();

int main() {
    input();
    output();
    return 0;
}

typedef struct pos {
    int y, x;
} pos;

typedef struct policy {
    int start, end;
    int (*iPolicy)(int), (*jPolicy)(int);
} policy;

pos operator+(pos a, pos b) {
    return pos{a.y + b.y, a.x + b.x};
}

int N, M, K;
int map[MAX_SIZE][MAX_SIZE];
pos dicePos;
pos test[] = {
        {0, 0},
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
};

/* 위 동 밑 서
 * X  북 X 남 */
int dice[][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
};

void input() {
    cin >> N >> M >> dicePos.y >> dicePos.x >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

bool isValid(pos p) {
    return ((0 <= p.y && p.y < N)
          &&(0 <= p.x && p.x < M));
}

bool move(int dir) {
    pos moved = dicePos + test[dir];
    if (isValid(moved)) {
        dicePos = moved;
        return true;
    }
    return false;
}

void roll(int dir) {
    int axis = dir / 3 + 1;
    int lr = dir % 2;
    auto func = axis == 1 ? [](int i){return i;} : [](int i){return (int)!i;};

    policy p = (lr == 0) ?
              policy{0, 3, [](int i){return i+1;}, func}
            : policy{3, 0, [](int i){return i-1;}, func};

    int i = p.start;
    int j = dir==3;
    int temp = dice[j][i];
    p.end = p.iPolicy(p.end);
    while (i != p.end) {
        int nextI = p.iPolicy(i);
        int nextJ = p.jPolicy(j);
        dice[j][i] = nextI != p.end ? dice[nextJ][nextI] : temp;
        i = nextI;
        j = nextJ;
    }
}

void copy() {
    int* num = &(map[dicePos.y][dicePos.x]);
    if (*num == 0) {
        *num = dice[0][2];
    }
    else {
        dice[0][2] = *num;
        *num = 0;
    }
}

void output() {
    for (int i = 0; i < K; i++) {
        int dir;
        cin >> dir;
        if (move(dir)) {
            roll(dir);
            copy();
            printf("%d\n", dice[0][0]);
        }
    }
}