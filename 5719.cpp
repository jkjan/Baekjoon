#include <iostream>
#include <list>
#include <queue>

#define INF 1000000000

using namespace std;

typedef pair<int, int> edge;

int makeGraph(int N, int M);
int dijkstra(list<edge>* graph, int S, int D);

int main(int argc, char** argv) {
	int N, M;
	cin >> N >> M;
	int i = 0;
	int answer;
	while (!(N == M && N == 0)) {
		answer = makeGraph(N, M);
		cout << answer << endl;
		cin >> N >> M;
		i++;
	}
	return 0;
}

int makeGraph(int N, int M) {
	list<edge> graph[500];
	int i;
	int U, V, P;
	int S, D;
	cin >> S >> D;
	for (i = 0; i < M; i++) {
		cin >> U >> V >> P;
		graph[U].push_back(edge(V, P));
	}
	int a = dijkstra(graph, S, D);
	if (a == INF) return -1;
	int b = dijkstra(graph, S, D);
	return b == INF ? -1 : b;
}

int dijkstra(list<edge>* graph, int S, int D) {
	list<edge> path[500];
	int dist[500];
	priority_queue<edge> pq;
	edge close;
	list<edge>::iterator itor;
	list<edge>::iterator ritor;
	int shorterPath, midway, midwayToDes, des;

	fill_n(dist, 500, INF);
	dist[S] = 0;
	pq.push(edge(0, S));

	while (!pq.empty()) {
		close = pq.top();
		midway = close.second;
		pq.pop();
		for (itor = graph[midway].begin(); itor != graph[midway].end(); ++itor) {
			midwayToDes = itor->second;
			shorterPath = dist[midway]+ midwayToDes;
			des = itor->first;
			if (dist[des] >= shorterPath) {
				if (dist[des] > shorterPath) {
					dist[des] = shorterPath;
					pq.push(edge(-dist[des], des));
					path[des].clear();
				}
				for (ritor = path[midway].begin(); ritor != path[midway].end(); ++ritor) {
					path[des].push_back(*ritor);
				}
				path[des].push_back(edge(midway, des));
			}
		}
	}

	for (itor = path[D].begin(); itor != path[D].end(); ++itor) {
		for (ritor = graph[itor->first].begin(); ritor != graph[itor->first].end(); ++ritor) {
			if (ritor->first == itor->second)
				graph[itor->first].erase(ritor++);
		}
	}
	return dist[D];
}