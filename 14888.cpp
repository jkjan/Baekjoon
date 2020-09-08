#include <iostream>
#include <vector>
#include <algorithm>

#define PLUS 0
#define MINUS 1
#define PROD 2
#define DIVID 3

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> op;
	int opCnt[4];
	int i, j;
	int max, min;
	int sum;

	max = -1000000001;
	min =  1000000001;

	for (i = 0; i< N; i++) {
		cin >> A[i];
	}

	sum = A[0];

	for (i = 0; i < 4; i++) {
		cin >> opCnt[i];
		for (j = 0; j < opCnt[i]; j++)
			op.push_back(i);
	}

	do {
		sum = A[0];
		for (j = 0; j < (int)op.size(); j++) {
			switch(op[j]) {
			case(PLUS):
				sum += A[j+1];
				break;
			case(MINUS):
				sum -= A[j+1];
				break;
			case(PROD):
				sum *= A[j+1];
				break;
			case(DIVID):
				sum /= A[j+1];
				break;
			default :
				break;
			}
		}

		max = sum > max ? sum : max;
		min = sum < min ? sum : min;

	} while(next_permutation(op.begin(), op.end()));

	cout << max << '\n' << min;
	return 0;
}