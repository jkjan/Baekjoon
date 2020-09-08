//============================================================================
// Name        : 1179.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	int k;
	int kI = 0;
	int who;
	cin >> n >> k;
	n++;
	queue<int> josephus;
	for (int i = 1; i < n; i++) {
		josephus.push(i);
	}
	cout << '<';
	while(josephus.size() > 1) {
		who = josephus.front();
		josephus.pop();

		if (kI < k-1) {
			josephus.push(who);
			kI++;
		}
		else {
			cout << who << ", ";
			kI = 0;
		}
	}

	cout << josephus.front();
	cout << '>';
	return 0;
}
