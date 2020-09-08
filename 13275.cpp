//============================================================================
// Name        : 13275.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char s[100001];
	char rs[200002];
	int max = -1;
	cin >> s;

	int len = strlen(s);
	int p = 1;
	rs[0] = '#';
	//cout << len << '\n';
	for (int i= 0; i < len; i++) {
		rs[p++] = s[i];
		rs[p++] = '#';
	}

	rs[p] = '#';
	int* A = new int[len*2];
	int R, P;
	R = P = 0;
	for (int i = 0; i< len*2; i++) {
		if (i > R)
			A[i] = 0;
		else
			A[i] = min(A[2*P-i], R-i);
		while (rs[i-A[i]-1] == rs[i+A[i]+1]) {
			A[i]++;
		}

		if (i+A[i] > R) {
			R = i + A[i];
			P = i;
		}
	}

	for (int i = 0; i < len*2; i++) {
		if (A[i] > max) {
			max = A[i];
		}
	}
	cout << max;

	return 0;
}
