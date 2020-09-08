#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int people;
	int i, j;
	int sum = 0;
	int line [1000];

	cin >> people;
	for (i = 0; i < people; i++) {
		cin >> line[i];
	}
	sort(line, line+people);

	for (i = 1; i <= people; i++) {
		for (j = 0; j < i; j++) {
			sum += line[j];
		}
	}

	cout << sum;
	return 0;
}
