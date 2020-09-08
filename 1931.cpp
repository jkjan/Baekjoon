#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> conf;

bool compare(conf a, conf b) {
	if (a.second == b.second)
		return (a.first < b.first);
	else
		return (a.second < b.second);
}

int main(int argc, char** argv) {
	int N;
	int i, j;
	int start, end;
	cin >> N;
	conf* confArr = new conf[N];
	for (i = 0; i < N; i++) {
		cin >> start >> end;
		confArr[i] = conf(start, end);
	}
	
	sort(confArr, confArr+N, compare);

	int confCnt = 0;
	int curEnd = 0;
	for (i = 0; i < N; i++) {
		if (confArr[i].first >= curEnd) {
			confCnt++;
			curEnd = confArr[i].second;
		}
	}
	cout << confCnt;
}