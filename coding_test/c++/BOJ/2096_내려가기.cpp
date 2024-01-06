#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int total_map[100001][3];
	int ans[2][3][2];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> total_map[i][j];
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			ans[i][j][0] = 0; ans[i][j][1] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				ans[1][j][0] = min(ans[0][j][0], ans[0][j + 1][0]) + total_map[i][j];
				ans[1][j][1] = max(ans[0][j][1], ans[0][j + 1][1]) + total_map[i][j];
			}
			else if (j == 2) {
				ans[1][j][0] = min(ans[0][j][0], ans[0][j - 1][0]) + total_map[i][j];
				ans[1][j][1] = max(ans[0][j][1], ans[0][j - 1][1]) + total_map[i][j];
			}
			else {
				ans[1][j][0] = min(min(ans[0][j][0], ans[0][j - 1][0]), ans[0][j + 1][0]) + total_map[i][j];
				ans[1][j][1] = max(max(ans[0][j][1], ans[0][j - 1][1]), ans[0][j + 1][1]) + total_map[i][j];
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1) {
					ans[i][j][0] = ans[i][j][1] = 0;
				}
				else {
					ans[i][j][0] = ans[i + 1][j][0];
					ans[i][j][1] = ans[i + 1][j][1];
				}
			}
		}
	}

	int min_ans = 2134567890;
	int max_ans = 0;

	for (int i = 0; i < 3; i++) {
		min_ans = min(min_ans, ans[0][i][0]);
		max_ans = max(max_ans, ans[0][i][1]);
	}

	cout << max_ans << ' ' << min_ans;
	return 0;
}