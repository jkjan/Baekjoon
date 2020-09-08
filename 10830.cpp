#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector< vector<ll> > matrix;
int N;

matrix input(ll* M);
matrix power(matrix m, ll n);
void printMatrix(matrix m);

int main() {
    ll M;
    matrix m = input(&M);
    m = power(m, M);
    printMatrix(m);
    return 0;
}

matrix operator*(const matrix & a, const matrix & b) {
    matrix c(N, vector<ll>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }
    return c;
}

matrix power(matrix a, ll n) {
    ll size = a.size();
    matrix res(size, vector<ll>(size));
    for (ll i = 0; i < size; i++) { // 단위 행렬
        res[i][i] = 1;
    }
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * a;
        }
        n /= 2;
        a = a * a;
    }
    return res;

}

matrix input(ll* M) {
    scanf(" %d %lld", &N, M);
    matrix m(N, vector<ll>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf(" %lld", &(m[i][j]));
        }
    }
    return m;
}

void printMatrix(matrix m) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%lld ", m[i][j]);
        }
        printf("\n");
    }
}
