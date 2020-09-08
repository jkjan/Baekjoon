#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 100000000

using namespace std;
typedef pair<int, int> pos;

int N, M;
int getMinChickenDistance(vector<pos> chicken, vector<pos> home);

int main() {
	int i, j, type;
	vector<pos> chicken;
	vector<pos> home;
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> type;
			if (type == 2) {
				chicken.push_back(pos(i, j));
			}
			else if (type == 1) {
				home.push_back(pos(i, j));
			}
		}
	}
	cout << getMinChickenDistance(chicken, home);
	return 0;
}

int getMinChickenDistance(vector<pos> chicken, vector<pos> home) {
	int i, j;
	bool* com = new bool[chicken.size()];
	int sum = 0;
	int minSum = INF;
	int minDist;
	vector<pos> survivor;

	for(i = 0; i < chicken.size() - M; i++) {
		com[i] = false;
	}
	for(i = chicken.size() - M; i < chicken.size(); i++) {
		com[i] = true;
	}
	do {
		for (i = 0; i < chicken.size(); i++) {
			if (com[i]) {
				survivor.push_back(chicken[i]);
				//cout << "(" << chicken[i].first << ", " << chicken[i].second << "), ";
			}
		}
		//cout << endl;

		for (i = 0; i < home.size(); i++) {
			//cout << nodeNum(home[i].first, home[i].second) << " starts ~ " << endl;
			minDist = INF;
			for (j = 0; j < survivor.size(); j++) {
				minDist = min(minDist, abs(home[i].first - survivor[j].first) + abs(home[i].second - survivor[j].second));
			}
			//cout << i << ' ' << minDist << endl;
			sum += minDist;
		}

		minSum = min(sum, minSum);
		sum = 0;
		survivor.clear();
	} while(next_permutation(com, com+chicken.size()));

	delete[] com;
	return minSum;
}
