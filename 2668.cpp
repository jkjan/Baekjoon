#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int* visited;

void dfs(int v, map< int, int >* graph);

int N;
vector <int> path;
map<int, int > cycles;

int main() {
	int n;
	int i, k; //iterator
	cin >> N;
	N++;
	visited = new int[N];

	map< int , int > graph;

	for (i = 1; i< N; i++) {
		cin >> n;
		visited[i] = 0;
		graph[i] = n;
	}

	for (i = 1; i < N; i++){
		if (visited[i] == 0) {
			for (k = 1; k < N; k++)
				visited[k] = 0;

			dfs(i, &graph);
			path.clear();
		}
	}

	cout << cycles.size() << '\n';
	for (map<int , int>::iterator itor = cycles.begin(); itor != cycles.end(); ++itor) {
		cout << itor->first << '\n';
	}

	return 0;
}

void dfs(int v, map< int, int >* graph) {
	visited[v]++;
	path.push_back(v);

	if (visited[graph->at(v)] == 0) {
		dfs(graph->at(v), graph);
	}

	else if (visited[graph->at(v)] == 1) {
		for (vector<int>::iterator itor3 = --path.end(); itor3 != path.begin(); --itor3) {
			if (*itor3 == graph->at(v)) {
				break;
			}
			else {
				cycles[*itor3] = 1;
			}
		}
		cycles[graph->at(v)] = 1;
	}
}