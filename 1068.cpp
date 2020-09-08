#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int cutting(int v, list<int>** graph);
int cut;

vector<int>* nodes;
int* visited;

int main() {
	int N, i;
	int root;

	cin >> N;
	visited = new int[N];

	for (i = 0; i < N; i++)
		visited[i] = 0;

	list<int>** tree = new list<int>*[N];

	for (i = 0; i < N; i++)
		tree[i] = new list<int>;

	nodes = new vector<int>(N);

	for (i = 0; i < N; i++) {
		cin >> nodes->at(i);
	}

	cin >> cut;
	
	for (i = 0; i < N; i++) {
		if (nodes->at(i) >= 0) {
			tree[nodes->at(i)]->push_back(i);
			tree[i]->push_back(nodes->at(i));
		}
		else
			root = i;
	}

	if (cut == root) {  //루트를 삭제
		cout <<"0";
		return 0;
	}

	for (i = 0; i < N; i++)
		tree[i]->sort();

	cutting(cut, tree);

	int cnt=0;

	for (i = 0; i<N; i++) {
		if (i != root && tree[i]->size() == 1)
			cnt++;
	}

	if (cnt == 0) { //루트만 남음
		cout <<"1";
		return 0;
	}

	cout <<cnt;

	delete(visited);
	delete(nodes);
	for (i = 0; i < N; i++)
		delete(tree[i]);
	delete(tree);

	return 0;
}

int cutting(int v, list<int>** graph) {
	list<int>::iterator itor = graph[v]->begin();
	while (!(graph[v]->size() > 1 && itor == graph[v]->end())) {
		if (graph[v]->size() == 0) {
			break;
		}
		if (visited[*itor] == 0 && *itor != nodes->at(cut)) {
			visited[*itor] = 1;
			cutting(*itor, graph);
			graph[v]->remove(*itor);
		}

		else {	
			list<int>::iterator vertex = find(graph[*itor]->begin(), graph[*itor]->end(), v);
			if (vertex != graph[*itor]->end()) {
				graph[*itor]->erase(vertex);
			}
			itor = graph[v]->erase(itor);
			if (graph[*itor]->size() == 0)
				break;
			continue;
		}
		itor = graph[v]->begin();
	}

	return 0;
}