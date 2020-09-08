#include <iostream>
#include <cstring>

bool tc();

int main() {
    int K;
    scanf(" %d", &K);
    getchar();
    for (int i = 1; i <= K; ++i) {
        printf("Data Set %d: %s", i, tc() ? "equal\n\n" : "not equal\n\n");
    }
    return 0;
}

void toNoneBlank(char** s) {
    while (**s == ' ') {
        ++*s;
    }
}

void input(char* s) {
    int i = 0;
    char c;
    int blanked = -1;
    int special = -1;

    while ((c = getchar()) != '\n') {
        if (c == ' ') {
            if (blanked == -1) {
                s[i] = c;
                blanked = i;
                i++;
            }
        }

        else {
            if (special != -1) {
                i = special + 1;
            }

            if (!isalpha(c) && !isdigit(c)) {
                if (c == '(' || c == '{' || c == '[')
                    c = '(';
                else if (c == ')' || c == '}' || c == ']')
                    c = ')';
                else if (c == ';' || c == ',')
                    c = ',';

                if (blanked != -1)
                    i = blanked;
                special = i;
            }

            else {
                special = -1;
                if (isalpha(c))
                    c = tolower(c);
            }

            s[i++] = c;
            blanked = -1;
        }
    }
    s[i] = 0;
    if (s[i-1] == ' ')
        s[i-1] = 0;
}

bool tc() {
    char *s1, *s2;
    s1 = new char[1001]; s2 = new char[1001];
    input(s1);
    input(s2);
    toNoneBlank(&s1); toNoneBlank(&s2);
    return strcmp(s1, s2) == 0;
}