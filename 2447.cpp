//============================================================================
// Name        : 2447.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

void stars(int N, int y, int x);
void printStars(int N);

bool** blueprint;

int main() {
	int N; //input
	int i; //iterator
	cin >> N;
	blueprint = new bool*[N];

	for (i = 0; i < N; i++) {
		blueprint[i] = new bool[N];
		memset(blueprint[i], false, sizeof(bool));
	}

	stars(N/3, 0, 0);
	printStars(N);

	for (i = 0; i < N; i++)
		delete(blueprint[i]);
	delete(blueprint);
	return 0;
}

void stars(int N, int y, int x) {
	if (N == 0) {
		blueprint[y][x] = true;
		return;
	}

	stars(N/3, y, x);
	stars(N/3, y, x+N);
	stars(N/3, y, x+2*N);

	stars(N/3, y+N, x);
	stars(N/3, y+N, x+2*N);

	stars(N/3, y+2*N, x);
	stars(N/3, y+2*N, x+N);
	stars(N/3, y+2*N, x+2*N);
}

void printStars(int N) {
	int i, j;
	for (i = 0; i< N; i++) {
		for (j = 0; j < N; j++) {
			if (blueprint[i][j] == true)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
}