#include <iostream>
using namespace std;

int cnt = 0;
int maxCnt = -1;
void hopIn(int num);
void hopOut(int num);
void getMax();

int main() {
    int a, b;
    for (int i = 0; i < 4; i++) {
        scanf(" %d %d", &a, &b);
        hopOut(a);
        hopIn(b);
        getMax();
    }
    printf("%d", maxCnt);
    return 0;
}

void hopIn(int num) {
    cnt += num;
}

void hopOut(int num) {
    cnt -= num;
}

void getMax() {
    maxCnt = max(maxCnt, cnt);
}