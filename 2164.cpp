#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Node {
public:
    int num;
    Node* next;
    Node() = default;
};

class MyQueue {
public:
    Node* queue;
    Node* head;
    Node* tail;
    int cnt;
    MyQueue() = default;
    void init();
    void push(int x);
    int pop();
    int size();
    bool empty();
    int front();
    int back();
};

void MyQueue::init() {
    Node *init = new Node;
    init->num = -1;
    init->next = nullptr;
    this->queue = init;
    this->head = this->queue;
    this->tail = this->queue;
    this->cnt = 0;
}

void MyQueue::push(int x) {
    Node* newNode = new Node;
    newNode->num = x;
    newNode->next = nullptr;
    this->tail->next = newNode;
    this->tail = newNode;
    this->cnt++;
}

int MyQueue::pop() {
    if (this->cnt == 0)
        return -1;
    int front = this->head->next->num;
    Node* willBeRemoved = this->head->next;
    this->head->next = this->head->next->next;
    this->cnt--;
    if (this->cnt == 0)
        this->init();
    delete [] willBeRemoved;
    return front;
}

int MyQueue::size() {
    return this->cnt;
}

bool MyQueue::empty() {
    return this->cnt == 0;
}

int MyQueue::front() {
    return this->cnt == 0 ? -1 : this->head->next->num;
}

int MyQueue::back() {
    return this->cnt == 0 ? -1 : this->tail->num;
}

int main() {
    MyQueue myQueue{};
    myQueue.init();
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        myQueue.push(i);

    while (myQueue.size() > 1) {
        myQueue.pop();
        if (myQueue.size() >= 2)
            myQueue.push(myQueue.pop());
    }

    cout << myQueue.front();

    return 0;
}
