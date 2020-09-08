#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

class edge {
public :
   int node;
   int weight;
    	edge(int node, int weight) {
         this->node = node;
         this->weight = weight;
      }
};

bool operator < (edge a, edge b) {
	return a.weight > b.weight;
}

int escape(int L, int R, int C);
int nodeNum(int R, int C, int i, int j, int k);
int dijkstra(vector<edge>* graph, int start, int exit);

int main() {
	int L, R, C;
	L = R = C = 1;
	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && L == R && R == C && C == 0) {
			return 0;
		}
		int d = escape(L, R, C);
		
		if (d < INF)
			cout << "Escaped in " << d << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
	}
}

int escape(int L, int R, int C) {
	int i, j, k;
	int start, exit;
	vector<edge> graph[27000];
	getchar();
	int build[30][30][30];
	for (i = 0; i < L; i++) {
		for (j = 0; j < R; j++) {
			for (k = 0; k < C; k++) {
				scanf("%c", &build[i][j][k]);
				//printf("%d ", nodeNum(R, C, i, j, k));
				if (build[i][j][k] == 'S') {
					start = nodeNum(R, C, i, j, k);
				//	cout << "starts at " << start << endl;
				}
				else if (build[i][j][k] == 'E') {
					exit = nodeNum(R, C, i, j, k);
				//	cout << "exits at " << exit << endl;
				}
				else if (build[i][j][k] == '#') {
					continue;
				}
				
				if (i > 0) {
					if (build[i-1][j][k] != '#') {
						graph[nodeNum(R, C, i, j, k)].push_back(edge(nodeNum(R, C, i-1, j, k), 1));
						graph[nodeNum(R, C, i-1, j, k)].push_back(edge(nodeNum(R, C, i, j, k), 1));
					}
				}
				
				if (j > 0) {
					if (build[i][j-1][k] != '#') {
						graph[nodeNum(R, C, i, j, k)].push_back(edge(nodeNum(R, C, i, j-1, k), 1));
						graph[nodeNum(R, C, i, j-1, k)].push_back(edge(nodeNum(R, C, i, j, k), 1));
					}
				}
				
				if (k > 0) {
					if (build[i][j][k-1] != '#') {
						graph[nodeNum(R, C, i, j, k)].push_back(edge(nodeNum(R, C, i, j, k-1), 1));
						graph[nodeNum(R, C, i, j, k-1)].push_back(edge(nodeNum(R, C, i, j, k), 1));
					}
				}
			}
			getchar();
			//cout << endl;
		}
		getchar();
		//cout << endl;
	}
	
	return dijkstra(graph, start, exit);
}

int nodeNum(int R, int C, int i, int j, int k) {
	return R*C*i + C*j + k;
}

int dijkstra(vector<edge>* graph, int start, int exit) {
	int dist[27000];
	priority_queue<edge> pq;
	edge close(0, 0);
	fill_n(dist, 27000, INF);
	dist[start] = 0;
	pq.push(edge(start, 0));
	
	while (!pq.empty()) {
		close = pq.top();
		pq.pop();
		for (vector<edge>::iterator itor = graph[close.node].begin(); itor != graph[close.node].end(); ++itor)	{
			if (dist[itor->node] > dist[close.node] + itor->weight) {
				dist[itor->node] = dist[close.node] + itor->weight;
				pq.push(edge(itor->node, dist[itor->node]));
			}
		}
	}
	
	return dist[exit];
}
