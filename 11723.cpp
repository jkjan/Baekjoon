#include <iostream>
#include <set>
#include <map>
#include <cstring>
#define MAX_SIZE 7
using namespace std;

void init(char names[][MAX_SIZE]);

typedef void (*func)(int);
struct compare {
    bool operator ()(char* a, char* b) {
        return strcmp(a, b) < 0;
    }
};

map<char*, func, compare> nameToFunc;
set<int> now;

void add(int x);
void remove(int x);
void check(int x);
void toggle(int x);
void all(int x);
void empty(int x);

int main() {
    char names[][MAX_SIZE] = {"add", "remove", "check", "toggle", "all", "empty"};
    init(names);
    int M;
    scanf(" %d", &M);
    for (int i = 0; i < M; ++i) {
        char name[MAX_SIZE];
        int x;
        scanf(" %s %d", name, &x);
        nameToFunc[name](x);
    }
    return 0;
}

void init(char names[][MAX_SIZE]) {
    nameToFunc[names[0]] = add;
    nameToFunc[names[1]] = remove;
    nameToFunc[names[2]] = check;
    nameToFunc[names[3]] = toggle;
    nameToFunc[names[4]] = all;
    nameToFunc[names[5]] = empty;
}

void add(int x) {
    now.insert(x);
}

void remove(int x) {
    if (now.count(x))
        now.erase(x);
}

void check(int x) {
    printf("%lu\n", now.count(x));
}

void toggle(int x) {
    if (now.count(x))
        remove(x);
    else
        add(x);
}

void all(int x) {
    for (int i = 1; i <= 20; i++)
        add(i);
}

void empty(int x) {
    now.clear();
}