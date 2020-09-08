#include <iostream>
#define MAX_SIZE 10000000 + 10000000 + 1
#define MAX 10000000
using namespace std;
int main() {
    int N, M;
    int* cards = new int[MAX_SIZE];
    fill(cards, cards + MAX_SIZE, 0);
    scanf(" %d", &N);
    for (int i = 0; i < N; i++) {
        int card;
        scanf(" %d", &card);
        cards[card + MAX]++;
    }

    scanf(" %d", &M);
    for (int i = 0; i < M; i++) {
        int card;
        scanf(" %d", &card);
        printf("%d ", cards[card + MAX]);
    }
    delete [] cards;
    return 0;
}