#include <iostream>
#include <stack>
#include <cstring>
#define MAX_SIZE 100
using namespace std;

char* input();
void tc(char* str);

int main() {
    while (true) {
        char* str = input();
        if (strlen(str) == 0)
            break;
        tc(str);
        delete [] str;
    }
    return 0;
}

char* input() {
    char* str = new char[MAX_SIZE];
    char* cur = str;
    while (true) {
        *cur = (char)getc(stdin);
        if (*cur == '.')
            break;
        cur++;
    }
    *cur = 0;
    getchar();
    return str;
}

bool closing(stack<char>* checker, char c) {
    if (checker->empty())
        return false;
    else if (checker->top() != (c - (c/93 + 1))) {
        return false;
    }
    else {
        checker->pop();
    }
    return true;
}

bool isBalanced(char* str) {
    stack<char> checker;

    while (*str) {
        if (*str == '(' || *str == '[') {
            checker.push(*str);
        }
        else if (*str == ')' || *str == ']') {
            if (!closing(&checker, *str))
                return false;
        }
        str++;
    }

    return checker.empty();
}

void tc(char* str) {
    printf("%s\n", (isBalanced(str)) ? "yes" : "no");
}