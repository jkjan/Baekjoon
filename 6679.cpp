#include <iostream>

using namespace std;

int jinsu(int num, int base) {
	int sum = 0;
	
	while (num > 0) {
		sum += (num % base);
		num /= base;
	}
	
	return sum;
}


int main(int argc, char** argv) {
	int dec, hex, duo;
	for (int i = 1000; i <= 9999; i++) {
		dec = jinsu(i, 10);
		hex = jinsu(i, 16);
		duo = jinsu(i, 12);
		if (( dec == hex ) && ( hex == duo ))
			cout << i << endl;
	}
	
	return 0;
}