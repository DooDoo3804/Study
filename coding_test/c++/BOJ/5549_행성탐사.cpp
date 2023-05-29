#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int total_map[1001][1001][3] = { 0 };

	int m; int n; int k;
	cin >> m >> n >> k;

	for (int i = 1; i < m + 1; i++) {
		string input;
		cin >> input;
		for (int j = 1; j < n + 1; j++) {
			total_map[i][j][0] = total_map[i][j - 1][0] + total_map[i - 1][j][0] - total_map[i - 1][j - 1][0];
			total_map[i][j][1] = total_map[i][j - 1][1] + total_map[i - 1][j][1] - total_map[i - 1][j - 1][1];
			total_map[i][j][2] = total_map[i][j - 1][2] + total_map[i - 1][j][2] - total_map[i - 1][j - 1][2];
			if (input[j - 1] == 'J') total_map[i][j][0]++;
			else if (input[j - 1] == 'O') total_map[i][j][1]++;
			else if (input[j - 1] == 'I') total_map[i][j][2]++;
		}
	}

	for (int i = 0; i < k; i++) {
		int x1; int y1; int x2; int y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans[3] = { 0 };
		ans[0] = total_map[x2][y2][0] + total_map[x1 - 1][y1 - 1][0] - total_map[x2][y1 - 1][0] - total_map[x1 - 1][y2][0];
		ans[1] = total_map[x2][y2][1] + total_map[x1 - 1][y1 - 1][1] - total_map[x2][y1 - 1][1] - total_map[x1 - 1][y2][1];
		ans[2] = total_map[x2][y2][2] + total_map[x1 - 1][y1 - 1][2] - total_map[x2][y1 - 1][2] - total_map[x1 - 1][y2][2];
		cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
	}

	return 0;
}