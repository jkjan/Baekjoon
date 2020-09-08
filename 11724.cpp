#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void dfs(int v);
bool* visited;
vector < vector<int> > graph;
int main() {
	int N, M;
	int u, v;
	int cnt = 0;
	int i;
	cin >> N >> M;
	N++;
	visited = new bool[N];

	for (i = 0; i < N; i++) {
		graph.push_back(vector<int>());
		visited[i] = false;
	}

	for (i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (i = 1; i < N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	for (i = 1; i < N; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;
	delete(visited);
	return 0;
}

void dfs(int v) {
	visited[v] = true;
	for (vector<int>::iterator itor = graph[v].begin(); itor != graph[v].end(); ++itor) {
		if (!visited[*itor]) {
			dfs(*itor);
		}
	}
}