#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>

using namespace std;

long long answer;

void n_z(int n, int x, int y) {
	if (n == 0) return;
	int n_1 = pow(2, n - 1);
	int n_x = x % n_1;
	int n_y = y % n_1;
	if (y / n_1 == 0 && x / n_1 == 0) {
		n_z(n - 1, n_x, n_y);
	}
	else if (x / n_1 == 0) {
		answer += pow(n_1, 2);
		n_z(n - 1, n_x, n_y);
	}
	else if (y / n_1 == 0) {
		answer += 2 * pow(n_1, 2);
		n_z(n - 1, n_x, n_y);
	}
	else {
		answer += 3 * pow(n_1, 2);
		n_z(n - 1, n_x, n_y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, r, c;
	cin >> n >> r >> c;

	n_z(n, r, c);

	cout << answer;
	return 0;
}