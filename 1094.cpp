#include <iostream>
#include <list>
using namespace std;

bool makeX(list<int>* sticks, int X);

int main() {
    int X;
    list<int> sticks(1, 64);
    scanf(" %d", &X);
    if (X == 64) {printf("1"); return 0;}
    while (!makeX(&sticks, X)) {}
    printf("%zu", sticks.size());
    return 0;
}

int sumStick(list<int>* sticks) {
    int sum = 0;
    for (auto & l : *sticks)
        sum += l;
    return sum;
}

bool makeX(list<int>* sticks, int X) {
    int minStick = sticks->back();
    int half = minStick/2;
    sticks->pop_back();
    sticks->push_back(half);
    int sum = sumStick(sticks);
    if (sum < X) {
        sticks->push_back(half);
    } else if (sum == X)
        return true;
    return false;
}