#include <iostream>
#include <queue>
#define MAX_SIZE 20
#define INF 20 * 20 + 1
using namespace std;

typedef struct pos {
    int y, x;
} pos;

pos operator+(pos a, pos b) {
    return {a.y + b.y, a.x + b.x};
}

struct compare {
    bool operator()(pos a, pos b) {
        if (a.y == b.y)
            return a.x > b.x;
        else
            return a.y > b.y;
    }
};

bool operator==(pos a, pos b) {
    return a.y == b.y && a.x == b.x;
}

int N;
int sea[MAX_SIZE][MAX_SIZE];
long scanf();
void input(pos* babyShark);
int bfs(int* size, int* bucket, pos* start);

int main() {
    int momma = 0;
    int moved;
    int size, bucket;
    size = 2;
    bucket = 0;
    pos babyShark;
    input(&babyShark);
    while ((moved = bfs(&size, &bucket, &babyShark)) != 0)
        momma += moved;
    printf("%d", momma);
    return 0;
}

long scanf() {
    char str[2];
    scanf(" %s", str);
    return strtol(str, nullptr, 10);
}

void input(pos* babyShark) {
    N = (int)scanf();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sea[i][j] = (int)scanf();
            if (sea[i][j] == 9) {
                *babyShark = {i, j};
                sea[i][j] = 0;
            }
        }
    }
}

bool isValid(pos p) {
    return (-1 < p.y && p.y < N) && (-1 < p.x && p.x < N);
}

void eatFish(int* size, int* bucket) {
    (*bucket)++;
    if (*size == *bucket){
        (*size)++;
//        printf("level up!\n\n");
        *bucket = 0;
    }
}

int bfs(int* size, int* bucket, pos* start) {
    queue<pos> willVisit;
    priority_queue<pos, vector<pos>, compare> cand;
    bool visited[MAX_SIZE][MAX_SIZE] = {false, };
    int dist[MAX_SIZE][MAX_SIZE] = {0,};
    int minDist = INF;
    bool flag = false;
    pos move[] = {
            {-1, 0}, {0, -1}, {0, 1}, {1, 0}
    };

    dist[start->y][start->x] = 0;
    visited[start->y][start->x] = true;
    willVisit.push(*start);

    while (!willVisit.empty() && !flag) {
        pos nowVisit = willVisit.front();
        willVisit.pop();
        for (auto m : move) {
            pos dest = nowVisit + m;
            if (isValid(dest)) {
                bool* visit = &(visited[dest.y][dest.x]);
                int fish = sea[dest.y][dest.x];
                if (!*visit && fish <= *size) {
                    dist[dest.y][dest.x] = dist[nowVisit.y][nowVisit.x] + 1;
//                    printf("%d %d moved to %d, %d\n", nowVisit.y, nowVisit.x, dest.y, dest.x);
                    if (fish < *size && fish != 0) {
                        if (dist[dest.y][dest.x] > minDist) {
//                            printf("end!\n");
                            flag = true;
                            break;
                        }
                        else {
                            minDist = dist[dest.y][dest.x];
                            cand.push(dest);
//                            printf("now %d %d, fish candidate : %d, %d\n", start->y, start->x, dest.y, dest.x);
                        }
                    }
                    willVisit.push(dest);
                    *visit = true;
                }
            }
        }
    }

    if (minDist != INF) {
        pos fish = cand.top();
//        printf("ate at %d, %d -> dist = %d\n", fish.y, fish.x, minDist);
        eatFish(size, bucket);
        sea[fish.y][fish.x] = 0;
        *start = fish;
        return minDist;
    }

    return 0;
}