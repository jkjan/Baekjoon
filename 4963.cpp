#include <iostream>
#include <stdio.h>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <cstdlib>

using namespace std;

int dfs(int v, vector< list<int> >* graph);
int getTheNumberOfIslands(int h, int w, int** island);

int* visited;

int main() {
	int w, h;

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			return 0;

		int ** island = new int*[h];
		for (int i = 0; i < h; i++)
			island[i] = new int[w];

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> island[i][j];
			}
		}
		getTheNumberOfIslands(h, w, island);
	}

	return 0;
}

int getTheNumberOfIslands(int h, int w, int** island) {
	vector< list<int> > graph;
	int node;
	int land = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (island[i][j] == 1) {
				graph.push_back(list<int>());

				if (i > 0) { //there is a space up above
					if (island[i - 1][j] != 0) {
						if (island[i - 1][j] == -1)
							node = 0;
						else
							node = island[i - 1][j];
						graph.at(node).push_back(land);
						graph.at(land).push_back(node);
					}
				}
				if (j > 0) { //there is a space left
					if (island[i][j - 1] != 0) {
						if (island[i][j - 1] == -1)
							node = 0;
						else
							node = island[i][j - 1];
						graph.at(node).push_back(land);
						graph.at(land).push_back(node);
					}
				}
				if (i > 0 && j > 0) { //there is a space
					if (island[i - 1][j - 1] != 0) {
						if (island[i - 1][j - 1] == -1)
							node = 0;
						else
							node = island[i - 1][j - 1];
						graph.at(node).push_back(land);
						graph.at(land).push_back(node);
					}
				}
				if (i > 0 && j < w-1) { //there is a space
					if (island[i - 1][j + 1] != 0) {
						if (island[i - 1][j + 1] == -1)
							node = 0;
						else
							node = island[i - 1][j + 1];
						graph.at(node).push_back(land);
						graph.at(land).push_back(node);
					}
				}
				if (land == 0)
					island[i][j] = -1;
				else
					island[i][j] = land;
				land++;
			}
		}
	}

	//graph complete
	if (land == 0) {
		cout << '0' << '\n';
		return 0;
	}
	visited = new int[land];
	for (int i = 0; i < land; i++) {
		visited[i] = 0;
	}

	int cnt = 0;
	for (int i = 0; i < land; i++) {
		if (visited[i] == 0) {
			dfs(i, &graph);
			cnt++;
		}
	}

	cout << cnt << '\n';
	delete(visited);

	return 0;
}

int dfs(int v, vector< list<int> >* graph) {
	visited[v] = 1;

	for (list<int>::iterator itor = graph->at(v).begin(); itor != graph->at(v).end(); ++itor) {
		if (visited[*itor] == 0) {
			dfs(*itor, graph);
		}
	}
	return 0;
}