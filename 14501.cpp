#include <iostream>
using namespace std;

int N;
int T[16], P[16];
int tos(int total, int i);

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	cout << tos(0, 1);

	return 0;
}

int tos(int total, int i) {
	// 모든 상담 일정을 확인
	if (i > N) {
		return total;
	}

	// 남은 상담 일정이 전부 1일 짜리 일 때
	int cnt = 0;
	int ptotal = 0;
	for (int j = i; j <= N; j++) {
		cnt += T[j];
		ptotal += P[j];
	}

	if (cnt == N - i + 1) {
		return total + ptotal;
	}

	int notToDo = tos(total, i+1);
	int toDo = total;

	// 상담에 걸리는 시간이 퇴사일을 넘어서지 않으면
	if (T[i] <= N - i + 1) {
		toDo = tos(total + P[i], i + T[i]);
	}
	return max(notToDo, toDo);
}
