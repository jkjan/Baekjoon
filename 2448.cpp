#include <iostream>
#include <cmath>
#define MAX_SIZE 3 * 2048
#define MAX_WIDTH (6 * 2048 - 1)/2
using namespace std;
typedef struct pos {
    int y, x;
} pos;

bool board[MAX_SIZE][MAX_WIDTH] = {false, };
int roots[11];
void init();
void makeTriangle(int n, pos root);

int main() {
    int n, k;
    scanf(" %d", &n);
    k = log2(n/3);
    init();
    makeTriangle(k, {0, roots[k]});
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < roots[k+1]; ++j) {
            printf("%c", board[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
    return 0;
}

void init() {
    roots[0] = 2;
    for (int i = 1; i <= 11; i++) {
        roots[i] = (6 * (int)pow(2, i) - 1)/2;
    }
}

void makeTriangle(int n, pos root) {
    if (n == 0) {
        board[root.y][root.x] = true;
        root.y++, root.x--;
        board[root.y][root.x] = board[root.y][root.x+2] = true;
        root.y++, root.x--;
        for (int i = 0; i < 5; ++i) {
            board[root.y][root.x + i] = true;
        }
        return;
    }

    int nextHeight = root.y + 3*(int)pow(2, n-1);
    int nextWidth = roots[n-1];
    nextWidth = nextWidth == 2 ? 3 : nextWidth;

    makeTriangle(n-1, root);
    makeTriangle(n-1, {nextHeight, root.x - nextWidth - (n != 1)});
    makeTriangle(n-1, {nextHeight, root.x + nextWidth + (n != 1)});
}