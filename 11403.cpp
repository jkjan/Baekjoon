//============================================================================
// Name        : 11403.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

void printPathTable(int nodes, bool** pathTable);
void floyd(int nodes, int start, bool** pathTable);

int main() {
	int nodes;
	int i, j;
	bool isPath;

	cin >> nodes;

	bool** pathTable = new bool*[nodes];

	for (i = 0; i< nodes; i++) {
		pathTable[i] = new bool[nodes];
		for (j = 0; j< nodes; j++) {
			cin >> isPath;
			pathTable[i][j] = isPath;
		}
	}

	for (i = 0; i<nodes; i++)
		floyd(nodes, i, pathTable);

	printPathTable(nodes, pathTable);

	return 0;
}

void printPathTable(int nodes, bool** pathTable) {
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j<nodes; j++)
			cout << pathTable[i][j] << ' ';
		cout << '\n';
	}
}

void floyd(int nodes, int start, bool** pathTable) {
	int i, j;

	for (i = 0; i < nodes; i++) {
		if (!pathTable[i][start] || i == start) {
			continue;
		}
		for (j = 0; j < nodes; j++) {
			if (pathTable[i][j])
				continue;
			if (pathTable[i][start] && pathTable[start][j]) {
				pathTable[i][j] = true;
			}
		}
	}
}