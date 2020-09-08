#include <iostream>
#include <cstring>
#include <stack>

void skip(const char* S, int* i);
void reverse(std::stack<char>* charStack);

int main() {
    char S[100001];
    std::stack<char> charStack;
    scanf(" %[^\n]", S);
    int len = strlen(S);

    for (int i = 0; i < len; ++i) {
        if (S[i] == '<' || S[i] == ' ') {
            reverse(&charStack);
            if (S[i] == '<')
                skip(S, &i);
            else if (S[i] == ' ')
                printf(" ");
        }
        else {
            charStack.push(S[i]);
        }
    }
    reverse(&charStack);
    return 0;
}

void skip(const char* S, int* i) {
    while (S[*i] != '>') {
        printf("%c", S[*i]);
        ++*i;
    }
    printf(">");
}

void reverse(std::stack<char>* charStack) {
    while (!charStack->empty()) {
        printf("%c", charStack->top());
        charStack->pop();
    }
}