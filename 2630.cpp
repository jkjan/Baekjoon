#include <iostream>
#define MAX_SIZE 128

int input();
bool paper[MAX_SIZE][MAX_SIZE];
int count[2] = {0, };
void isSame(int i, int j, int limit, bool with);

int main() {
    int N = input();
    isSame(0, 0, N, paper[0][0]);
    for (auto c : count)
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

void isSame(int i, int j, int limit, bool with) {
    int iLimit = i + limit;
    int jLimit = j + limit;
    bool flag = false;
    for (int m = i; m < iLimit && !flag; m++) {
        for (int n = j; n < jLimit; n++) {
            if (paper[m][n] != with) {
                flag = true;
                break;
            }
        }
    }

    if (!flag) {
        count[with]++;
    }

    else {
        int nextLimit = limit/2;
        for (int k = 0; k < 2; ++k) {
            for (int l = 0; l < 2; ++l) {
                int nextI = i + (k * nextLimit);
                int nextJ = j + (l * nextLimit);
                int nextWith = paper[nextI][nextJ];
                isSame(nextI, nextJ, nextLimit, nextWith);
            }
        }
    }
}