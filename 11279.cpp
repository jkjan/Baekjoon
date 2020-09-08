#include <iostream>
#include <queue>

typedef std::priority_queue<int> pq ;

int pop(pq* Q);

int main() {
    pq Q;
    Q.push(0);
    int N;
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        int cmd;
        scanf(" %d", &cmd);
        if (cmd == 0)
            printf("%d\n", pop(&Q));
        else
            Q.push(cmd);
    }

    return 0;
}

int pop(pq* Q) {
    if (Q->top() == 0)
        return 0;
    int ret = Q->top();
    Q->pop();
    return ret;
}