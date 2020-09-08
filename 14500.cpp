#include <iostream>
#define MAX_SIZE 500
using namespace std;

char i_block[4][4][4] = {
        1, 1, 1, 1,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
        0, 0, 0, 1,  0, 0, 0, 1,  0, 0, 0, 1,  0, 0, 0, 1,
        0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  1, 1, 1, 1,
        1, 0, 0, 0,  1, 0, 0, 0,  1, 0, 0, 0,  1, 0, 0, 0
};

char t_block[4][4][4] = {
        1, 0, 0, 0,  1, 1, 0, 0,  1, 0, 0, 0,  0, 0, 0, 0,
        1, 1, 1, 0,  0, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
        0, 0, 1, 0,  0, 1, 1, 0,  0, 0, 1, 0,  0, 0, 0, 0,
        0, 0, 0, 0,  0, 1, 0, 0,  1, 1, 1, 0,  0, 0, 0, 0
};

char s_block[4][4][4] = {
        1, 0, 0, 0,  1, 1, 0, 0,  0, 1, 0, 0,  0, 0, 0, 0,
        0, 1, 1, 0,  1, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
        0, 1, 0, 0,  0, 1, 1, 0,  0, 0, 1, 0,  0, 0, 0, 0,
        0, 0, 0, 0,  0, 1, 1, 0,  1, 1, 0, 0,  0, 0, 0, 0
};

char z_block[4][4][4] = {
        0, 1, 0, 0,  1, 1, 0, 0,  1, 0, 0, 0,  0, 0, 0, 0,
        1, 1, 0, 0,  0, 1, 1, 0,  0, 0, 0, 0,  0, 0, 0, 0,
        0, 0, 1, 0,  0, 1, 1, 0,  0, 1, 0, 0,  0, 0, 0, 0,
        0, 0, 0, 0,  1, 1, 0, 0,  0, 1, 1, 0,  0, 0, 0, 0
};

char l_block[4][4][4] = {
        1, 0, 0, 0,  1, 0, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,
        1, 1, 1, 0,  1, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
        0, 1, 1, 0,  0, 0, 1, 0,  0, 0, 1, 0,  0, 0, 0, 0,
        0, 0, 0, 0,  0, 0, 1, 0,  1, 1, 1, 0,  0, 0, 0, 0
};

char j_block[4][4][4] = {
        0, 1, 0, 0,  0, 1, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,
        1, 0, 0, 0,  1, 1, 1, 0,  0, 0, 0, 0,  0, 0, 0, 0,
        1, 1, 0, 0,  1, 0, 0, 0,  1, 0, 0, 0,  0, 0, 0, 0,
        1, 1, 1, 0,  0, 0, 1, 0,  0, 0, 0, 0,  0, 0, 0, 0
};

char o_block[4][4][4] = {
        1, 1, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
        1, 1, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
        1, 1, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
        1, 1, 0, 0,  1, 1, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,
};

int N, M;
int paper[MAX_SIZE][MAX_SIZE];

void input();
int tryEvery();

int main() {
    input();
    printf("%d", tryEvery());
    return 0;
}

void input() {
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %d", paper[i]+j);
        }
    }
}

typedef struct pos {
    int y, x;
} pos;

template <class T> T* get(T a[][MAX_SIZE], pos p) {
    return &(a[p.y][p.x]);
}

bool isValid(pos p) {
    return ((-1 < p.y && p.y < N) && (-1 < p.x && p.x < M));
}

int put(char block[][4], int y, int x) {
    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            pos here = {i + y, j + x};
            if (!isValid(here))
                continue;
            if (block[i][j]) {
                sum += *get(paper, here);
                cnt++;
            }
        }
    }

    return (cnt == 4 ? sum : 0);
}

int tryPerBlock(char block[][4][4]) {
    int maxCnt = 0;

    for (int i = -1; i < N; i++) {
        for (int j = -1; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                maxCnt = max(maxCnt, put(block[k], i, j));
            }
        }
    }

    return maxCnt;
}

int tryEvery() {
    int maxCnt = 0;

    auto blocks = {
            i_block, t_block, s_block, z_block,
            l_block, j_block, o_block
    };

    for (auto b : blocks) {
        maxCnt = max(maxCnt, tryPerBlock(b));
    }

    return maxCnt;
}