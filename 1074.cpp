#include <iostream>
#include <cmath>

void draw(int n, int i, int j);

int cnt = 0;
int r, c;

int main() {
    int N;
    scanf(" %d %d %d", &N, &r, &c);
    draw(pow(2, N), 0, 0);
    return 0;
}

int getRegion(int i, int j) {
    if (r < i && c < j)
        return 0;
    else if (r < i && j <= c)
        return 1;
    else if (i <= r && c < j)
        return 2;
    else
        return 3;
}

int indexMover[][2] = {
        {0, 0}, {0, 1}, {1, 0}, {1, 1}
};

void draw(int n, int i, int j) {
    if (n == 1) {
        if (i == r && j == c)
            printf("%d", cnt);
        return;
    }
    int nextN = n/2;
    int region = getRegion(i + nextN, j + nextN);
    int* index = indexMover[region];
    cnt += region * pow(nextN, 2);
    draw(nextN, i + index[0] * nextN, j + index[1] * nextN);
}
