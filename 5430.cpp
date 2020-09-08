#include <iostream>
#include <cstring>
#include <queue>
#define MAX_CMD 100001
#define MAX_SIZE 100000
#define MAX_ARR 6 * MAX_SIZE + 1 * 99999 + 2 + 1

using namespace std;

void tc();

int main() {
    int T;
    scanf(" %d", &T);
    for (int i = 0; i < T; i++) {
        tc();
    }
    return 0;
}

void tc() {
    int n;
    char cmd[MAX_CMD];
    char arr_str[MAX_ARR];
    deque<int> arr;
    char* tkn;
    scanf(" %s", cmd);
    scanf(" %d", &n);
    scanf(" %s", arr_str);
    tkn = strtok(arr_str, "[,]");
    while (tkn != NULL) {
        arr.push_back(atoi(tkn));
        tkn = strtok(NULL, "[,]");
    }
    int len = strlen(cmd);
    int d = 1;
    for (int j = 0; j < len; j++) {
        if (cmd[j] == 'R') {
            d *= -1;
        }
        else {
            if (n == 0) {
                printf("error\n");
                return;
            }
            if (d == 1) {
                arr.pop_front();
            }
            else {
                arr.pop_back();
            }
            n--;
        }
    }

    auto start = d == 1 ? arr.begin() : arr.end();
    auto end = d == 1 ? arr.end() : arr.begin();

    printf("[");
    while (!arr.empty()) {
        if (d == 1) {
            printf("%d", arr.front());
            arr.pop_front();
        }
        else {
            printf("%d", arr.back());
            arr.pop_back();
        }
        if (!arr.empty())
            printf(",");
    }

    printf("]\n");
}
