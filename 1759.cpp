#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int L, C;
	int j;
	int i = 0;
	char key[16];
	char can[16];
	int con;
	int vow;

	cin >> L >> C;

	for (i = 0; i < C; i++) {
		cin >> key[i];
	}

	sort(key, key+C);

	bool* com = new bool[C];

	for (i = 0; i < L; i++) {
		com[i] = false;
	}
	for (i = L; i < C; i++) {
		com[i] = true;
	}

	do {
		con = j = vow = 0;

		for (i = 0; i < C; i++) {
			if (!com[i]) {
				can[j] = key[i];
				if (can[j] == 'a' || can[j] == 'e' || can[j] == 'i' || can[j] == 'o' || can[j] == 'u') {
					vow++;
				}
				else
					con++;
				j++;
			}
		}

		if (vow >= 1 && con >= 2) {
			can[L] = 0;
			cout << can << endl;
		}

	} while (next_permutation(com, com + C));

	delete[] com;

	return 0;
}
