#include <iostream>
using namespace std;

int main() {
	int price;
	int i = 0;
	int coins[6] = {500, 100, 50, 10, 5, 1};
	int cnt = 0;
	int addCnt;
	cin >> price;
	price = 1000 - price;
	while (price > 0 && i < 6) {
		if (price >= coins[i]) {
			addCnt = price / coins[i];
			price -= (addCnt * coins[i]);
			cnt += addCnt;
		}
		i++;
	}
	cout << cnt;
	return 0;
}
