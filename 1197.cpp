#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class edge { // 엣지에 대한 정보를 담은 클래스
public:
	int node1; // 출발 노드
	int node2; // 도착 노드
	int weight; // 가중치
	edge(){}
	edge(int a, int b, int w) { // 생성자
		this->node1 = a;
		this->node2 = b;
		this->weight = w;
	}
};

bool operator < (edge a, edge b) { // 오름차순 비교 연산자
	return a.weight > b.weight;
}

int label[10001]; // 노드의 라벨

int kruskal (priority_queue<edge> edges, int V);

int main(int argc, char** argv) {
	int V, E; // 노드, 엣지의 개수
	int u, v, w; // 출발 노드, 도착 노드, 가중치
	priority_queue<edge> edges; // 엣지가 저장되는 우선순위 큐
	int i; // 반복자

	cin >> V >> E;

	for (i = 1; i <= V; i++) { // 노드들의 라벨링
		label[i] = i;
	}

	for (i = 0; i < E; i++) { // 그래프의 입력
		cin >> u >> v >> w;
		edges.push(edge(u, v, w)); // 우선순위 큐에 엣지를 추가
	}

	cout << kruskal(edges, V);

	return 0;
}

int kruskal (priority_queue<edge> edges, int V) {
	int i; // 반복자
	edge a;
	int change;
	int weightSum = 0;

	while(!edges.empty()) {
		a = edges.top();
		edges.pop();

		if (label[a.node1] != label[a.node2]) { // 같은 라벨의 노드가 아니라면
			weightSum += a.weight;
			change = label[a.node2];

			for (i = 1; i <= V; i++) { // 라벨을 같게 하여 union 작업을 진행한다
				if (label[i] == change)
					label[i] = label[a.node1];
			}
		}
	}

	return weightSum;
}
