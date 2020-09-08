//============================================================================
// Name        : 1389.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void floyd(int users, int who, int** baconTable, int** prevNode);

int main() {
	int users, connections;
	int from, to;
	int i, j;

	cin >> users >> connections;
	users++;

	int** baconTable = new int*[users];
	int** prevNode = new int*[users];

	for (i = 0; i<users; i++) {
		baconTable[i] = new int[users];
		prevNode[i] = new int[users];
		for (j = 0; j < users; j++) {
			baconTable[i][j] = 0;
			prevNode[i][j] = 0;
		}
	}

	for (i = 0; i < connections; i++) {
		cin >> from >> to;
		baconTable[from][to] = 1;
		baconTable[to][from] = 1;
		prevNode[from][to] = from;
		prevNode[to][from] = to;
	}

	for (i = 1; i < users; i++) {
		floyd(users, i, baconTable, prevNode);
	}

	int kevinBaconNum;
	int minKevinBaconNum = 0;
	int winner = 0;

	for (i = 1; i<users; i++) {
		kevinBaconNum = 0;
		for (j = 1; j < users; j++) {
			kevinBaconNum += baconTable[i][j];
		}
		if (minKevinBaconNum == 0 || kevinBaconNum < minKevinBaconNum) {
			minKevinBaconNum = kevinBaconNum;
			winner = i;
		}
	}
	cout << winner;

	return 0;
}

void floyd(int users, int who, int** baconTable, int** prevNode) {
	int i, j;

	for (i = 1; i < users; i++) {
		if (prevNode[i][who] == 0 || i == who)
			continue;
		for (j = 1; j < users; j++) {
			if (i == j || prevNode[who][j] == 0)
				continue;
			if (baconTable[i][j] == 0 || baconTable[i][j] > baconTable[i][who] + baconTable[who][j]) {
				baconTable[i][j] = baconTable[i][who] + baconTable[who][j];
				prevNode[i][j] = who;
			}
		}
	}
}