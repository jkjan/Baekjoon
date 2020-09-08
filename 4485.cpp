#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

class edge {
public:
	int to;
	int weight;
	edge(int to, int weight) {
		this->to = to;
		this->weight = weight;
	}
};

bool operator < (edge a, edge b) {return a.weight > b.weight;}

int nodeNum(int i, int j);
int dijkstra(int N);

int main() {
	int N = 1;
	int i = 1;
	while (1) {
		cin >> N;
		if (N == 0) break;
		cout << "Problem " << i++ << ": "<< dijkstra(N) << endl;
	}
	return 0;
}

int nodeNum(int N, int i, int j) {
	return i*N + j;
}

int dijkstra(int N) {
	int cave[125][125];
	int i, j;
	vector<edge> graph[15625];
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> cave[i][j];
			if (i > 0) {
				graph[nodeNum(N, i, j)].push_back(edge(nodeNum(N, i-1, j), cave[i-1][j]));
				graph[nodeNum(N, i-1, j)].push_back(edge(nodeNum(N, i, j), cave[i][j]));
			}

			if (j > 0) {
				graph[nodeNum(N, i, j)].push_back(edge(nodeNum(N, i, j-1), cave[i][j-1]));
				graph[nodeNum(N, i, j-1)].push_back(edge(nodeNum(N, i, j), cave[i][j]));
			}
		}
	}
	
	int distChart[15625];
	priority_queue<edge> pq;
	edge close = edge(0, 0);
	distChart[0] = cave[0][0];
	fill_n(distChart+1, 15624, INF);
	pq.push(edge(0 , cave[0][0]));

	while(!pq.empty()) {
		close = pq.top();
		pq.pop();
		
		for(vector<edge>::iterator itor = graph[close.to].begin(); itor != graph[close.to].end(); ++itor) {
			if (distChart[itor->to] > distChart[close.to] + itor->weight) {
				distChart[itor->to] = distChart[close.to] + itor->weight;
				pq.push(edge(itor->to, distChart[itor->to]));
			}
		}
	}
	
	return distChart[N*N-1];
}