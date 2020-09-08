//============================================================================
// Name        : 11728.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int* merge(int N, int* A, int M, int* B);

int main() {
	int N, M;
	int i;
	cin >> N >> M;
	int* A = new int[N];
	int* B = new int[M];

	for (i = 0; i< N; i++)
		cin >> A[i];

	for (i = 0; i < M; i++)
		cin >> B[i];

	int* mergedArray = merge(N, A, M, B);

	for (i = 0; i < N+M; i++) {
		cout << mergedArray[i] << ' ';
	}

	delete(mergedArray);

	return 0;
}

int* merge(int N, int* A, int M, int* B) {
	int* mergedArray = new int[N+M];

	int index1 = 0;
	int index2 = 0;
	int index3 = 0;

	while (index1 < N && index2 < M) {
		mergedArray[index3++] = A[index1] <= B[index2] ? A[index1++] : B[index2++];
	}

	while (index1 < N) {
		mergedArray[index3++] = A[index1++];
	}

	while (index2 < M) {
		mergedArray[index3++] = B[index2++];
	}

	return mergedArray;
}
