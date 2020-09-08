#include <iostream>

#define W true
#define B false

using namespace std;

int N, M;
bool** board;

int recolored(bool head, int y, int x);

int main() {
	int min = 65;
	int minCan;
	cin >> N >> M;
	int i, j; // iterator
	board = new bool*[N];
	char wb;

	for (i = 0; i < N; i++) {
		board[i] = new bool[M];
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> wb;
			board[i][j] = (wb == 'W') ? W : B;
		}
	}

	// input ---------------------------------

	for(i = 0; i <= N-8; i++) {
		for (j = 0; j <= M-8; j++) {
			minCan = recolored(board[i][j], i, j);
			min = min < minCan ? min : minCan;

			minCan = recolored(!board[i][j], i, j);
			min = min < minCan ? min : minCan;
		}
	}

	cout << min;

	for (i = 0; i < N; i++)
		delete(board[i]);
	delete(board);

	return 0;
}

int recolored(bool head, int y, int x) {
	int cnt = 0;

	int i, j;
	bool turn;

	for (i = y; i < y+8; i++) {
		turn = !head;
		for (j = x; j < x+8; j++) {
			turn = !turn;
			if (board[i][j] != turn) {
				cnt++;
			}
		}
		head = !head;
	}

	return cnt;
}
