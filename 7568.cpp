//============================================================================
// Name        : 7568.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int> > body; // the bodies array expressed with vector


int getRank(int i);

int main() {
	int N; // the number of people
	int x, y; // each weight and height
	int i; // iterator
	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> x >> y;
		body.push_back(pair<int, int>(x, y));
	}

	// input end ----------------------------

	for (i = 0; i < N; i++) {
		cout << getRank(i) << ' ';
	}

	return 0;
}

int getRank(int i) {
	int cnt = 0;
	pair<int, int> nowLooking = body.at(i);

	vector< pair<int, int> >::iterator itor;
	for (itor = body.begin(); itor != body.end(); ++itor) {
		if (itor->first > nowLooking.first && itor->second > nowLooking.second) {
			cnt++;
		}
	}

	return cnt+1;
}
