#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, b;
	cin >> n >> m >> b;
	int total_map[501][501] = { 0 };

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> total_map[i][j];
		}
	}

	int t_ans = 2134567890;
	int h_ans = 0;

	for (int k = 0; k <= 256; k++) {
		int time = 0;
		int block = b;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (total_map[i][j] > k) {
					block += total_map[i][j] - k;
					time += 2 * (total_map[i][j] - k);
				} if (total_map[i][j] < k) {
					block -= k - total_map[i][j];
					time += k - total_map[i][j];
				}
			}
		}
		if (block < 0) continue;
		if (t_ans >= time) {
			t_ans = time;
			h_ans = k;
		}
	}

	cout << t_ans << ' ' << h_ans;
	
	return 0;
}