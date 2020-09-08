#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int N, i;
	scanf("%d", &N);

	int* A = new int[N];
	int* B = new int[N];

	for (i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (i = 0; i < N; i++) {
		cin >> B[i];
	}

	sort(A, A + N);
	sort(B, B + N, compare);

	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}

	printf("%d", sum);

	delete(A);
	delete(B);

	return 0;
}