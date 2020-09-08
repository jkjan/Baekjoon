#include <iostream>
#include <stack>
#include <cstring>
#include <map>
#define MAX_SIZE 4 + 1 + 6 + 1
using namespace std;

typedef stack<int> sInt;
typedef int (*fptr)(sInt *);
struct compare {
    int operator()(const char* a, const char* b) {
        return strcmp(a, b) < 0;
    }
};

int top(sInt*);
int size(sInt*);
int empty(sInt*);
int pop(sInt*);
void push(sInt*, int);

int main() {
    int N;
    map<char*, fptr, compare> strToFunc;
    char commands[4][256] = {"top", "size", "empty", "pop"};
    strToFunc[commands[0]] = top;
    strToFunc[commands[1]] = size;
    strToFunc[commands[2]] = empty;
    strToFunc[commands[3]] = pop;

    sInt stk;
    scanf(" %d", &N);
    for (int i = 0; i < N; i++) {
        int num;
        char option[6];
        char command[MAX_SIZE];
        scanf(" %[^\n]", command);
        int type = sscanf(command, " %s %d", option, &num);
        if (type == 2)
            push(&stk, num);
        else
            printf("%d\n", strToFunc[option](&stk));
    }
    return 0;
}

void push(sInt* stk, int num) {
    stk->push(num);
}

int top(sInt* stk) {
    if (stk->empty())
        return -1;
    else
        return stk->top();
}

int size(sInt* stk) {
    return stk->size();
}

int empty(sInt* stk) {
    return stk->empty();
}

int pop(sInt* stk) {
    if (stk->empty())
        return -1;
    else {
        int top = stk->top();
        stk->pop();
        return top;
    }
}