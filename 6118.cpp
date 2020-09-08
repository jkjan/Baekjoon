#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

vector<int>* makeGraph(int N, int M);
int* bfs(vector<int>* graph, int N);

int main() {
	int N, M, i;
	int max = 0;
	int maxNode;
	int cnt = 0;
	cin >> N >> M;
	vector<int>* graph = makeGraph(N, M);
	int* dist = bfs(graph, N);

	for (i = 1; i <= N; i++) {
		if (dist[i] > max) {
			max = dist[i];
			maxNode = i;
		}
	}

	for (i = 1; i <= N; i++) {
		if (dist[i] == max)
			cnt++;
	}

	cout << maxNode << ' ' << max << ' ' << cnt;

	delete[] graph;
	delete[] dist;
	return 0;
}

vector<int>* makeGraph(int N, int M) {
	vector<int>* graph = new vector<int>[N+1];
	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}

	return graph;
}

int* bfs(vector<int>* graph, int N) {
	int* dist = new int[N+1];
	bool visited[20001];
	int visiting;
	vector<int>::iterator itor;
	for (int i = 0; i < N; i++) {
		visited[i] = false;
		dist[i] = INF;
	}
	dist[1] = 0;
	visited[1] = true;

	queue<int> willVisit;
	willVisit.push(1);

	while (!willVisit.empty()) {
		visiting = willVisit.front();
		willVisit.pop();
		for(itor = graph[visiting].begin(); itor != graph[visiting].end(); ++itor) {
			if (!visited[*itor]) {
				dist[*itor] = dist[visiting] + 1;
				visited[*itor] = true;
				willVisit.push(*itor);
				//cout << "visiting " << *itor << endl;
			}
		}
	}

	return dist;
}
