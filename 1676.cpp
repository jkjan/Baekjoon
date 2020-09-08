#include <iostream>

int twos = 0;
int fives = 0;

void counter(int n);

int main() {
    int N;
    scanf(" %d", &N);
    for (; N >= 1; --N) {
        counter(N);
    }
    printf("%d", std::min(twos, fives));
    return 0;
}

void extract(int n, int* counter, int which) {
    int i = 1;
    int num = which;
    while (n >= num && n % num == 0) {
        i++;
        num *= which;
    }
    *counter += i - 1;
}

void counter(int n) {
    extract(n, &twos, 2);
    extract(n, &fives, 5);
}
