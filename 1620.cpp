#include <iostream>
#include <map>
#include <cstring>
#define MAX_SIZE 100000 + 1
using namespace std;

int N, M;

struct compare {
    bool operator()(char *a, char *b) {
        return strcmp(a, b) < 0;
    }
};

map<char*, int, compare> nameToIndex;
char* indexToName[MAX_SIZE];

void input();
void output();

int main() {
    for (int i = 1; i < MAX_SIZE; i++) {
        indexToName[i] = new char[21];
    }
    input();
    output();

    return 0;
}

void input() {
    scanf(" %d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf(" %s", indexToName[i]);
        nameToIndex[indexToName[i]] = i;
    }
}

void output() {
    for (int i = 1; i <= M; i++) {
        char find[21];
        scanf(" %s", find);
        if (isalpha(find[0]))
            printf("%d\n", nameToIndex[find]);
        else
            printf("%s\n", indexToName[atoi(find)]);
    }
}