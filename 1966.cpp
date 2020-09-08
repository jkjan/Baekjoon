#include <iostream>
#include <list>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

bool desc(int a, int b) {return a > b;}
void printQueue();

int main() {
	int T;
	cin >> T;
	int i;

	for (i = 0; i < T; i++) {
		printQueue();
	}
	return 0;
}

void printQueue() {
	int N, M;
	int candidate;
	int popped;
	int i;
	int cnt = 0;
	list <int> priority;
	queue <int> pQ;

	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> candidate;
		priority.push_back(candidate);
		if (i == M) candidate *= -1;
		pQ.push(candidate);
	}

	priority.sort(desc);

	while (1) {
		popped = pQ.front();
		pQ.pop();
		if ((int)abs(popped) < priority.front()) {
			pQ.push(popped);
		}

		else {
			priority.pop_front();
			cnt++;

			if (popped < 0) {
				break;
			}
		}
	}

	cout << cnt << '\n';
}