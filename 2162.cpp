#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 3000

using namespace std;

typedef long long ll;

typedef struct pos {
    ll x, y;
} pos;

typedef struct line {
    pos pos1, pos2;
} line;

int ccw(pos p1, pos p2, pos p3);
bool isIntersect(line l1, line l2);
int unionParent(int a, int b);
int getParent(int x);

int parent[MAX_SIZE];
int groupSizes[MAX_SIZE];

int main() {
    int N;
    int maxGroupCnt = 1;
    int groupCnt = 0;
    line lines[MAX_SIZE];

    scanf(" %d", &N);

    for (int i = 0; i < N; i++) {
        parent[i] = i;
        groupSizes[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
        lines[i] = {{x1, y1}, {x2, y2}};

        for (int j = 0; j < i; j++) {
            if (getParent(i) == getParent(j))
                continue;

            if (isIntersect(lines[i], lines[j])) {
                maxGroupCnt = max(maxGroupCnt, unionParent(i, j));
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (parent[i] == i)
            groupCnt++;
    }

    printf("%d\n%d", groupCnt, maxGroupCnt);

    return 0;
}

int ccw(pos p1, pos p2, pos p3) {
    ll temp1 = (p2.x - p1.x) * (p3.y - p1.y);
    ll temp2 = (p2.y - p1.y) * (p3.x - p1.x);
    ll criterion = temp1 - temp2;

    if (criterion == 0)
        return 0;
    else {
        return criterion > 0 ? 1 : -1;
    }
}

bool isIntersect(line l1, line l2) {
    pos a = l1.pos1;
    pos b = l1.pos2;
    pos c = l2.pos1;
    pos d = l2.pos2;

    int ct1 = ccw(a, b, c) * ccw(a, b, d);
    int ct2 = ccw(c, d, a) * ccw(c, d, b);

    if (ct1 == 0 && ct2 == 0) {
        pair<int, int> aa = make_pair(l1.pos1.x, l1.pos1.y);
        pair<int, int> bb = make_pair(l1.pos2.x, l1.pos2.y);
        pair<int, int> cc = make_pair(l2.pos1.x, l2.pos1.y);
        pair<int, int> dd = make_pair(l2.pos2.x, l2.pos2.y);

        if (aa > bb) {
            swap(aa, bb);
        }
        if (cc > dd) {
            swap(cc, dd);
        }
        return cc <= bb && aa <= dd;
    }

    return ct1 <= 0 && ct2 <= 0;
}

int getParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}

int unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if (groupSizes[a] < groupSizes[b])
        swap(a, b);
    parent[b] = a;
    groupSizes[a] += groupSizes[b];
    return groupSizes[a];
}