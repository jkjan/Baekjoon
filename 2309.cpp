#include <iostream>

using namespace std;

void merge(int s1, int e1, int s2, int e2, int* array);
void mergeSort(int s, int e, int* array);

int main () {
	int dwarves[9];
	bool found = 0;
	int sum = 0;

    for (int i = 0; i < 9; i++) {
    	cin >> dwarves[i];
    	sum += dwarves[i];
	}

    sum -= 100;

    for (int i = 0; i<8; i++) {
    	for (int j = i+1; j < 9; j++) {
    		if (dwarves[i] + dwarves[j] == sum) {
    			dwarves[i] = 0;
    			dwarves[j] = 0;
    			found = true;
    			break;
    		}
    	}
    	if (found == true)
    		break;
    }

    mergeSort(0, 8, dwarves);

    for (int i = 2; i < 9; i++) {
    	cout << dwarves[i] << '\n';
    }

    return 0;
}

void merge(int s1, int e1, int s2, int e2, int* array) {
	int* array3 = new int[e1 - s1 + e2 - s2 + 2];
	int oneIndex = s1;
	int twoIndex = s2;
	int threeIndex = 0;
	while (oneIndex <= e1 && twoIndex <= e2) {
		array3[threeIndex++] = (array[oneIndex] >= array[twoIndex]) ? array[twoIndex++] : array[oneIndex++];
	}
	while (oneIndex <= e1) {
		array3[threeIndex++] = array[oneIndex++];
	}

	while (twoIndex <= e2) {
		array3[threeIndex++] = array[twoIndex++];
	}
	for (int i = s1; i <= e2; i++)
		array[i] = array3[i-s1];
}

void mergeSort(int s, int e, int* array) {
	if (s >= e)
		return;
	int m = (s+e)/2;
	mergeSort(s, m, array);
	mergeSort(m+1, e, array);
	merge(s, m, m+1, e, array);
}