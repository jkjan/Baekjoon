#include <iostream>
#include <queue>

void answer();
struct compare {
    bool operator()(int a, int b) {
        return a > b;
    }
};
std::priority_queue<int, std::vector<int>, compare> pq;

int main() {
    int N;
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        answer();
    }
    return 0;
}

int pop() {
    if (pq.empty())
        return 0;
    int top = pq.top();
    pq.pop();
    return top;
}

void answer() {
    int command;
    scanf(" %d", &command);
    if (command)
        pq.push(command);
    else
        printf("%d\n", pop());
}