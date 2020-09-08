#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N;
int** ability;

int teamDivider();
int getDifference(int* dividedTeam);

int main() {
	int i, j; // iterator
	cin >> N;
	ability = new int*[N];
	for (i = 0; i < N; i++) {
		ability[i] = new int[N];
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			cin >> ability[i][j];
	}

	// input -------------------------------

	cout << teamDivider();

	for (i = 0; i < N; i++)
		delete(ability[i]);

	delete (ability);
	return 0;
}

int teamDivider() {
	vector<bool> com(N);
	int* dividedTeam = new int[N];
	int min = 1001;
	int minCan;
	int i; // iterator
	int aTeam, bTeam;
	aTeam = 0;
	bTeam = N/2;

	for (i = 0; i < N/2; i++)
		com[i] = false;
	for (i = N/2; i < N; i++)
		com[i] = true;

	do {
		for (i = 0; i < N; i++) {
			if (com[i]) {
				dividedTeam[aTeam++] = i;
			}
			else {
				dividedTeam[bTeam++] = i;
			}
		}

		minCan = getDifference(dividedTeam);
		min = min < minCan ? min : minCan;
		aTeam = 0;
		bTeam = N/2;

	}while (next_permutation(com.begin(), com.end()));

	delete(dividedTeam);

	return min;
}

int getDifference(int* dividedTeam) {
	int aTeamAbility = 0;
	int bTeamAbility = 0;
	int i, j; // iterator

	for (i = 0; i < N/2; i++) {
		for (j = 0; j < N/2; j++) {
			if (i != j) {
				aTeamAbility += ability[dividedTeam[i]][dividedTeam[j]];
			}
		}
	}

	for (i = N/2; i < N; i++) {
		for (j = N/2; j < N; j++) {
			if (i != j) {
				bTeamAbility += ability[dividedTeam[i]][dividedTeam[j]];
			}
		}
	}

	return aTeamAbility >= bTeamAbility ? aTeamAbility - bTeamAbility : bTeamAbility - aTeamAbility;
}