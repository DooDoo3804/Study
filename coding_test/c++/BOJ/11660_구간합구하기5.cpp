#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; int m;
	cin >> n >> m;

	int total_map[1025][1025] = { 0 };
	int sum_map[1025][1025] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> total_map[i + 1][j + 1];
			sum_map[i + 1][j + 1] = sum_map[i + 1][j] + sum_map[i][j + 1] + total_map[i + 1][j + 1] - sum_map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int x1; int y1; int x2; int y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum_map[x2][y2] + sum_map[x1 - 1][y1 - 1] - sum_map[x2][y1 - 1] - sum_map[x1 - 1][y2]  << "\n";
	}


	return 0;
}