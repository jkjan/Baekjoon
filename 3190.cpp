#include <iostream>
#include <vector>
#define MAX_SIZE 101
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

typedef struct _pos {
    int r, c;
} pos;

typedef struct _snake {
    int dir;
    pos p;
} snake;

bool operator == (pos a, pos b) {
    return a.r == b.r && a.c == b.c;
}

void input(int* N, int* K, bool board[][MAX_SIZE], char* change);
bool move(int* N, snake* head, vector<pos>* body, bool board[][MAX_SIZE]);
void changeDir(snake* head, char dir);

int main() {
    bool board[MAX_SIZE][MAX_SIZE] = {false, };
    snake head = snake{RIGHT, pos{1, 1}};
    int N, K;
    char change[10001] = {0, };
    vector<pos> body;
    int sec = 0;

    input(&N, &K, board, change);

    while (move(&N, &head, &body, board)) {
        changeDir(&head, change[++sec]);
    }

    printf("%d", sec+1);

    return 0;
}

void input(int* N, int* K, bool board[][MAX_SIZE], char* change) {
    int x, y, L;

    cin >> *N;
    cin >> *K;

    for (int i = 0; i < *K; i++) {
        cin >> x >> y;
        board[x][y] = true;
    }

    cin >> L;

    for (int i = 0; i < L; i++) {
        int sec;
        char dir;
        cin >> sec >> dir;
        change[sec] = dir;
    }
}

void changeDir(snake* head, char dir) {
    // 왼쪽
    if (dir == 'L') {
        if (head->dir > 0)
            head->dir--;
        else
            head->dir = LEFT;
    }
    
    // 오른쪽
    else if (dir == 'D') {
        head->dir = (++head->dir)%4;
    }
}

bool move(int* N, snake* head, vector<pos>* body, bool board[][MAX_SIZE]) {
    int dif[][4] = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
    };

    // 머리가 움직이기로 예정된 곳
    int newR = head->p.r + dif[head->dir][0];
    int newC = head->p.c + dif[head->dir][1];

    // 1. 범위 넘어가거나
    if (!((1 <= newR && newR <= *N) && (1 <= newC && newC <= *N))) {
        return false;
    }

    // 2. 자기 몸에 닿을 시 false 반환 후 종료
    else {
        for (auto i : *body) {
            if (i == pos{newR, newC})
                return false;
        }
    }

    // 사과 먹었다면 꼬리 추가
    if (board[head->p.r][head->p.c]) {
        board[head->p.r][head->p.c] = false;
        body->push_back(head->p);
    }

    // 몸 움직이기
    for (int i = body->size()-1; i >= 1; i--) {
        body->at(i) = body->at(i-1);
    }
    if (!body->empty())
        body->at(0) = head->p;

    // 머리 움직이기
    head->p = pos{newR, newC};
    
    return true;
}