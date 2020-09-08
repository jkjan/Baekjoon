#include <iostream>
#define MAX_SIZE 2187

int input();
void cutPaper(int i, int j, int n);
int paper[MAX_SIZE][MAX_SIZE];
int count[3] = {0, };

int main() {
    int N = input();
    cutPaper(0, 0, N);
    for(auto c : count)
        printf("%d\n", c);
    return 0;
}

int input() {
    int N;
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf(" %d", &(paper[i][j]));
        }
    }
    return N;
}

void cutPaper(int i, int j, int n) {
    int iTill = i + n;
    int jTill = j + n;
    int init = paper[i][j];
    bool flag = false;
    for (int k = i; k < iTill && !flag; k++) {
        for (int l = j; l < jTill; l++) {
            if (init != paper[k][l]) {
                flag = true;
                break;
            }
        }
    }
    n /= 3;
    if (flag) {
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                cutPaper(i + k * n, j + l * n, n);
            }
        }
    }
    else {
        count[init+1]++;
    }
}