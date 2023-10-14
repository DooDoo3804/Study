#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int total_map[51][51] = { 0 };
int visited[51][51] = { 0 };
int moves[4][2] = { {0,1}, {0, -1}, {1,0},{-1,0} };

void check_map(int x, int y, int cnt, int n, int m) {
	visited[y][x] = 1;
	for (auto move : moves) {
		int next_y = y + move[0];
		int next_x = x + move[1];
		if (0 <= next_x && next_x < m && 0 <= next_y && next_y < n) {
			if (visited[next_y][next_x] == 0 && total_map[next_y][next_x] == 1) check_map(next_x, next_y, cnt, n, m);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		for (int i = 0; i < 51; i++) {
			fill(total_map[i], total_map[i] + 51, 0);
			fill(visited[i], visited[i] + 51, 0);
		}
		int cnt = 0;

		int m, n, k;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			total_map[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (total_map[i][j] == 1 && visited[i][j] == 0) {
					cnt++;
					check_map(j, i, cnt, n, m);
				}
			}
		}
		cout << cnt << '\n';
	}


	return 0;
}