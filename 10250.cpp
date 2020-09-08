#include <iostream>
#include <cmath>
#define MAX_STR 5

void tc();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; i++) {
        tc();
    }
    return 0;
}

void itoa(char** str, int num, int digit) {
    while (digit >= 0) {
        *((*str)++) = (char)('0'+(num/pow(10, digit--)));
        num %= 10;
    }
}

char* indexToRoomNum(int i, int j) {
    char* str = new char[MAX_STR];
    char* cur = str;
    int floorDigit = (int)log10(i);
    int roomDigit = (int)log10(j);
    itoa(&cur, i, floorDigit);
    if (roomDigit == 0)
        *(cur++) = '0';
    itoa(&cur, j, roomDigit);
    *cur = 0;
    return str;
}

void tc() {
    int H, W, N;
    char* roomNum;
    bool flag = false;
    scanf(" %d %d %d", &H, &W, &N);
    for (int j = 1; j <= W && !flag; j++) {
        for (int i = 1; i <= H; i++) {
            roomNum = indexToRoomNum(i, j);
            if (--N == 0) {
                printf("%s\n", roomNum);
                flag = true;
                break;
            }
        }
    }
    delete [] roomNum;
}