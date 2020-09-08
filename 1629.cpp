#include <iostream>

int multiplication (long long int A, long long int B, int C);

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << multiplication(A, B, C);
	return 0;
}

int multiplication (long long int A, long long int B, int C) {
	if (B <= 1) return A % C;
	long long int dd = multiplication(A, B/2, C);
	return (dd % C * dd % C * ((B%2)? A%C : 1) ) % C;
}