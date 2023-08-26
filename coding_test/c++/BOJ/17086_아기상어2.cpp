#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; int m;
	cin >> n >> m;

	int total_map[50][50] = { 0 };
	int visited[50][50] = { 0 };
	int dist[50][50] = { 0 };
	for (int i = 0; i < 50; i++) {
		fill(dist[i], dist[i] + 50, 50);
	}
	int answer = 0;
	int moves[8][2] = { {-1, -1}, {-1, 1}, {-1, 0}, {1,0}, {1, -1}, {1, 1}, {0, 1}, {0, -1} };
	queue<vector<int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			total_map[i][j] = input;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (total_map[i][j] == 1) {
				dist[i][j] = 0;
				continue;
			}
			q = queue<vector<int>>();
			for (int i = 0; i < 50; i++) {
				fill(visited[i], visited[i] + 50, 0);
			}

			q.push({ i, j, 0 });
			visited[i][j] = 1;

			while (!q.empty()) {
				auto now = q.front();
				q.pop();

				for (auto move : moves) {
					int next_x = now[0] + move[0];
					int next_y = now[1] + move[1];
					if (0 <= next_x && next_x < n && 0 <= next_y && next_y < m && visited[next_x][next_y] == 0) {
						if (total_map[next_x][next_y] == 1) {
							dist[i][j] = min(dist[i][j], now[2] + 1);
						}
						else if (total_map[next_x][next_y] == 0) {
							q.push({ next_x, next_y, now[2] + 1 });
							visited[next_x][next_y] = 1;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answer = max(answer, dist[i][j]);
		}
	}

	cout << answer;

	return 0;
}