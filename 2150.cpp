#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int N, V;
bool* visited;
int pCnt = 0;
int scc = 0;
map<int, int, greater<int> > post;
vector < set<int> > sccs;

void visitedClear();
void dfs(int, set<int>*, bool);
set<int>* reverse(set<int>*);
bool compare(set<int> a, set<int> b);

int main() {
	int n, v;
	int i;

	cin >> N >> V;
	N++;
	
	visited = new bool[N];
	visitedClear();
	set<int>* graph = new set<int>[N];

	for (i = 0; i < V; i++) {
		cin >> n >> v;
		graph[n].insert(v);
	}

	set<int>* reversed = reverse(graph);

	for (i = 1; i < N; i++) {
		if (!visited[i]) {
			dfs(i, reversed, false);
		}
	}
	visitedClear();

	for (map<int, int, greater<int> >::iterator itor = post.begin(); itor != post.end(); ++itor) {
		if (!visited[itor->second]) {
			sccs.push_back(set<int>());
			dfs(itor->second, graph, true);
			scc++;
		}
	}

	sort(sccs.begin(), sccs.end(), compare);

	cout << scc << '\n';
	for (i = 0; i < scc; i++) {
		for (set<int>::iterator itor = sccs[i].begin(); itor != sccs[i].end(); ++itor) {
			cout << *itor << ' ';
		}
		cout << -1 << endl;
	}

	return 0;
}

void dfs(int v, set<int>* graph, bool real) {
	visited[v] = true;
	pCnt++;

	if (real) {
		sccs[scc].insert(v);
	}

	for (set<int>::iterator itor = graph[v].begin(); itor != graph[v].end(); ++itor) {
		if (!visited[*itor]) {
			dfs(*itor, graph, real);
		}
	}

	post[++pCnt] = v;
}

void visitedClear() {
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
}

set<int>* reverse(set<int>* graph) {
	set<int>* reversed = new set<int>[N];
	for (int i = 1; i < N; i++) {
		for (set<int>::iterator itor = graph[i].begin(); itor != graph[i].end(); ++itor) {
			reversed[*itor].insert(i);
		}
	}
	return reversed;
}

bool compare(set<int> a, set<int> b) {
	return *next(a.begin(), 0) < *next(b.begin(), 0);
}