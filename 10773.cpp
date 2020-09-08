#include <iostream>
#include <stack>
using namespace std;

int main() {
    int sum = 0;
    int K;
    stack<int> numbers;

    scanf(" %d", &K);

    for (int i = 0; i < K; i++) {
        int num;
        scanf(" %d", &num);
        if (num == 0) {
            numbers.pop();
        }
        else {
            numbers.push(num);
        }
    }

    while (!numbers.empty()) {
        sum += numbers.top();
        numbers.pop();
    }

    printf("%d", sum);

    return 0;
}