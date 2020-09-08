#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <cstdlib>

using namespace std;

int* visited;

void dfs(int v, vector< vector<int> >* graph);
void printGraph(int v, vector< vector<int> >* graph);

int main() {
	int computers, connections, from, to;
	int i; //iterators
	cin >> computers >> connections;
	computers++;

	visited = new int[computers];
	vector< vector<int> > graph(computers);
	for (i = 0; i< computers; i++)
		graph.push_back(vector<int>());

	for (i = 0; i < connections; i++) {
		cin >> from >> to;
		graph.at(from).push_back(to);
		graph.at(to).push_back(from);
	}

	dfs(1, &graph);
	//printGraph(computers, &graph);
	int cnt = 0;

	for (i = 1; i<computers; i++) {
		if (visited[i] == 1) {
			cnt++;
		}
	}

	cout << cnt-1;

	return 0;
}

void dfs(int v, vector< vector<int> >* graph) {
	visited[v] = 1;

	for (vector<int>::iterator itor = graph->at(v).begin(); itor != graph->at(v).end(); ++itor) {
		if (visited[*itor] == 0) {
			//cout << v << " goes to " << *itor << '\n';
			//cnt++;
			dfs(*itor, graph);
		}
	}
}

void printGraph(int v, vector< vector<int> >* graph) {
	for (int i = 1; i<v; i++) {
		cout << i << " : ";
		for (vector<int>::iterator itor = graph->at(i).begin(); itor != graph->at(i).end(); ++itor) {
			cout << *itor << " ";
		}
		cout << "\n";
	}
}
