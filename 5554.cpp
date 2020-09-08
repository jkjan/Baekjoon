#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    int temp;
    cin >> temp;
    sum += temp;
    cin >> temp;
    sum += temp;
    cin >> temp;
    sum += temp;
    cin >> temp;
    sum += temp;
    cout << sum/60 << '\n' << sum%60;
    return 0;
}