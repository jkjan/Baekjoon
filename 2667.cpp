//============================================================================
// Name        : 2667.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(int v, vector< vector<int> >* graph);

int* visited;
int houseCnt;

int main() {
	int mapSize;
	char isHouse;
	int i, j;
	int nodes = 0;

	cin >> mapSize;

	int** map = new int*[mapSize];
	//char** charMap = new char*[mapSize];

	for (i = 0; i< mapSize; i++) {
		map[i] = new int[mapSize];
		//charMap[i] = new char[mapSize];
	}

	vector< vector<int> > graph;
	graph.push_back(vector <int> ());

	for (i = 0; i < mapSize; i++) {
		for (j = 0; j < mapSize; j++) {
			cin >> isHouse;
			map[i][j] = isHouse - '0';
		}
	}

	for (i = 0; i < mapSize; i++) {
			for (j = 0; j < mapSize; j++) {
				//cin >> isHouse;
				//map[i][j] = isHouse;
				if (map[i][j] == 1) {
					map[i][j] = ++nodes;
					graph.push_back(vector<int>());

					if (i > 0) {
						if (map[i - 1][j] != 0) {
							graph.at(map[i-1][j]).push_back(nodes);
							graph.at(nodes).push_back(map[i-1][j]);
						}
					}

					if (j > 0) {
						if (map[i][j -1] != 0) {
							graph.at(map[i][j-1]).push_back(nodes);
							graph.at(nodes).push_back(map[i][j-1]);
						}
					}
				}
			}
		}

	visited = new int[++nodes];

	for (i = 0; i < nodes; i++)
		visited[i] = 0;

	int cnt = 0;
	vector<int> house;

	for (i = 1; i < nodes; i++) {
		houseCnt = 0;
		if (visited[i] == 0) {
			dfs(i, &graph);
			cnt++;
			house.push_back(houseCnt);
		}
	}

	sort(house.begin(), house.end());
	cout << cnt << '\n';

	for (i = 0; i < cnt; i++)
		cout << house.at(i) << '\n';

	for (i = 0; i< mapSize; i++)
		delete(map[i]);

	delete(map);
	delete(visited);

	return 0;
}

void dfs(int v, vector< vector<int> >* graph) {
	visited[v] = 1;
	houseCnt++;
	for (vector<int>::iterator itor = graph->at(v).begin(); itor != graph->at(v).end(); ++itor) {
		if (visited[*itor] == 0) {
			dfs(*itor, graph);
		}
	}
}
