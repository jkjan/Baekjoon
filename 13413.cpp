#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int test();

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
       cout << test() << endl;
    }

    return 0;
}

int test() {
    int N;
    int B, W;
    B = W = 0;

    cin >> N;
    string initial, goal;
    cin >> initial >> goal;

    for (int i = 0; i < N; i++) {
        if (initial[i] != goal[i]) {
           if (initial[i] == 'B') {
               B++;
           }

           else
               W++;
        }
    }

    int result = abs(B - W) + min(B, W);

    return result;
}