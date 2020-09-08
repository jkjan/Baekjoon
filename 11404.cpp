#include <iostream>
#include <map>
#define MAX_SIZE 100 + 1
using namespace std;

typedef long long ll;

int n, m;

void input(ll dist[][MAX_SIZE]);
void floyd(ll dist[][MAX_SIZE]);
void output(ll dist[][MAX_SIZE]);

int main() {
    ll dist[MAX_SIZE][MAX_SIZE];
    ll inf = 10000000001;
    fill(&(dist[0][0]), &(dist[MAX_SIZE-1][MAX_SIZE]), inf);
    input(dist);
    floyd(dist);
    output(dist);
    return 0;
}

void input(ll dist[][MAX_SIZE]) {
    int a, b, c;
    scanf(" %d", &n);
    scanf(" %d", &m);
    for (int i = 0; i < m; i++) {
        scanf(" %d %d %d", &a, &b, &c);
        dist[a][b] = dist[a][b] < c ? dist[a][b] : c;
    }
}

void floyd(ll dist[][MAX_SIZE]) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue;
                ll newDist = dist[i][k] + dist[k][j];
                if (dist[i][j] > newDist) {
                    dist[i][j] = newDist;
                }
            }
        }
    }
}

void output(ll dist[][MAX_SIZE]) {
    ll inf = 10000000001;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%lld ", dist[i][j] == inf ? 0 : dist[i][j]);
        }
        printf("\n");
    }
}