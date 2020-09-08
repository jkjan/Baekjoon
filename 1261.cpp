#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

class edge {
public :
   int to;
   int weight;
    	edge(int to, int weight) {
         this->to = to;
         this->weight = weight;
      }
};

bool operator < (edge a, edge b) {
   return (a.weight > b.weight);
}

int M, N; // 가로, 세로 
bool room[101][101];

int nodeNum (int i, int j);
int dijkstra(vector<edge>* graph);

int main(int argc, char** argv) {
   cin >> N >> M;
   vector<edge> graph[10001];
   int i, j;
   char c;
   int weight;
   
   for (i = 1; i <= M; i++) {
      for (j = 1; j <= N; j++) {
         cin >> c;
         room[i][j] = (c - '0');
      }
   }
   
   for (i = 1; i <= M; i++) {
      for (j = 1; j <= N; j++) {
         if (i > 1) {
            weight = room[i][j] + room[i-1][j];
            //cout << "(" << i << ", " << j << ")부터 " << "(" << i-1 << ", " << j << ")의 거리는 " << weight << endl;
            graph[nodeNum(i, j)].push_back(edge(nodeNum(i-1, j), weight));
            graph[nodeNum(i-1, j)].push_back(edge(nodeNum(i, j), weight));
         }
         
         if (j > 1) {
            weight = room[i][j] + room[i][j-1];
            //cout << "(" << i << ", " << j << ")부터 " << "(" << i << ", " << j-1 << ")의 거리는 " << weight << endl;
            graph[nodeNum(i, j)].push_back(edge(nodeNum(i, j-1), weight));
            graph[nodeNum(i, j-1)].push_back(edge(nodeNum(i, j), weight));
         }
      }
   }
   
   int wallCnt = dijkstra(graph);
   
   cout << wallCnt;
   
   return 0;
}

//int distance(vector<bool> dist, int i, int j) {
//   return (dist.size() == 0 && i != j ? INF : 0);
//}

int dijkstra(vector<edge>* graph) {
   int* distChart = new int[N*M+1];
   int row;
   int col;
   fill_n(distChart, N*M+1, INF);
   distChart[1] = 0;
   
   priority_queue<edge> pq;
   edge shortest(0, 0);
   pq.push(edge(1, 0));
   
   while (!pq.empty()) {
      shortest = pq.top();
      pq.pop();
      for (vector<edge>::iterator itor = graph[shortest.to].begin(); itor != graph[shortest.to].end(); ++itor) {
         if (distChart[itor->to] > distChart[shortest.to] + itor->weight) {
            distChart[itor->to] = distChart[shortest.to] + itor->weight;
            if (itor->to % N == 0) {
            	row = itor->to / N;
            	col = M;
			}
			else {
				row = itor->to / N + 1;
				col = itor->to % N;
			}
            pq.push(edge(itor->to, distChart[itor->to]));
         }
      }
   }

//	//   
//   for (int i = 1; i <= N*M; i++) {
//      cout << distChart[i] << ' ';
//      if (i % N == 0)
//         cout << endl;
//   }
//   
   //cout << endl;

   row = distChart[N*M]/2;
   delete[] distChart;
   return row;
}

int nodeNum (int i, int j) {
   return (i-1)*N + j;
}









