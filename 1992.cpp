#include <iostream>
#include <string>
#define MAX_SIZE 64

int input();
bool picture[MAX_SIZE][MAX_SIZE];
std::string isSame(int i, int j, int limit, bool with);

int main() {
    int N = input();
    std::cout << isSame(0, 0, N, picture[0][0]);
    return 0;
}

int input() {
    int N;
    scanf(" %d", &N);
    getchar();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            picture[i][j] = getchar() - '0';
        }
        getchar();
    }
    return N;
}

std::string isSame(int i, int j, int limit, bool with) {
    std::string str;
    int iLimit = i + limit;
    int jLimit = j + limit;
    bool flag = false;
    for (int m = i; m < iLimit && !flag; m++) {
        for (int n = j; n < jLimit; n++) {
            if (picture[m][n] != with) {
                flag = true;
                break;
            }
        }
    }

    if (!flag)
        str += std::to_string(with);
    else {
        int nextLimit = limit/2;
        str += '(';
        for (int k = 0; k < 2; ++k) {
            for (int l = 0; l < 2; ++l) {
                int nextI = i + (k * nextLimit);
                int nextJ = j + (l * nextLimit);
                int nextWith = picture[nextI][nextJ];
                str += isSame(nextI, nextJ, nextLimit, nextWith);
            }
        }
        str += ')';
    }
    return str;
}