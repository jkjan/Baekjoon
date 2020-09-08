#include <iostream>
#include <vector>
#include <algorithm> 
#include <utility>
#include <map>

using namespace std;

bool* visited;
int cnt;
vector < vector <int> > graph;
map < pair<int, int> , int> food;

void dfs(int);
int surroundCheck(int, int, int*);

int main() {
	int N, M, K; //세로 길이, 가로 길이, 음식물 쓰레기의 개수
	int r, c; //음식물 좌표
	int i, j; // 반복자
	int max = 0;
	int posNum;
	int checker[4][2] = {
		{-1 , 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};

	cin >> N >> M >> K;
	
	visited = new bool[K];

	for (i = 0; i < K; i++) {
		graph.push_back(vector< int >());
		visited[i] = false;
	}

	for (i = 0; i < K; i++) {
		cin >> r >> c;
		food[pair<int, int>(r, c)] =  i;
		for (j = 0; j < 4; j++) {
			if ((posNum = surroundCheck(r, c, checker[j])) != -1) {
				graph[i].push_back(posNum);
				graph[posNum].push_back(i);
			}
		}
	}

	for (i = 1; i < K; i++) {
		cnt = 0;
		if (!visited[i]) {
			dfs(i);
			max = cnt > max ? cnt : max;
		}
	}

	cout << max;

	delete(visited);
	return 0;
}

void dfs(int v) {
	visited[v] = true;
	cnt++;
	for (vector< int >::iterator itor = graph[v].begin(); itor != graph[v].end(); ++itor) {
		if (!visited[*itor]) {
			dfs(*itor);
		}
	}
}

int surroundCheck(int y, int x, int* checker) {
	pair<int, int> pos = pair<int, int>(y + checker[0], x + checker[1]);
	return food.count(pos) ? food[pos] : -1;
}