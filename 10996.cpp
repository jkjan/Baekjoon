#include <iostream>

void zigzag(int n);

int main() {
    int N;
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        zigzag(N);
    }
    return 0;
}

void zigzag(int n) {
    bool isOdd = n % 2;
    int half = n/2;
    int up = half + isOdd;
    int down = half;
    for (int i = 0; i < up; i++)
        printf("* ");
    printf("\n");
    for (int i = 0; i < down; i++)
        printf(" *");
    printf("\n");
}
