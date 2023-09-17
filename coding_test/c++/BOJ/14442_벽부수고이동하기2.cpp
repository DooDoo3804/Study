#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

#define INF 2134567890

using namespace std;

struct node {
	int x, y, cnt, wall;
};

bool operator<(node a, node b) {
	return a.cnt > b.cnt;
}

int visited[1000][1000][11];
int dp[1000][1000][11];
int total_map[1000][1000];
int moves[4][2] = { {0,1} ,{0, -1}, {1,0}, {-1,0} };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			for (int ii = 0; ii < 11; ii++)
				dp[i][j][ii] = INF;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			total_map[i][j] = input[j];
		}
	}

	priority_queue<node> q;
	visited[0][0][0] = 1;
	dp[0][0][0] = 1;
	q.push({ 0, 0, 1, 0 });

	while (!q.empty()) {
		auto now = q.top();
		q.pop();

		for (auto move : moves) {
			int next_x = now.x + move[0];
			int next_y = now.y + move[1];
			if (0 > next_x || next_x >= n || 0 > next_y || next_y >= m) continue;
			
			if (total_map[next_x][next_y] == 49 && now.wall == k) continue;

			if (next_x == n && next_y == m) {
				dp[next_x][next_y][now.wall] = min(dp[next_x][next_y][now.wall], now.cnt + 1);
				continue;
			}

			if (visited[next_x][next_y][now.wall] == 0 && total_map[next_x][next_y] == 49) {
				if (dp[next_x][next_y][now.wall + 1] <= now.cnt + 1) continue;
				visited[next_x][next_y][now.wall + 1] = 1;
				dp[next_x][next_y][now.wall + 1] = now.cnt + 1;
				q.push({ next_x, next_y, now.cnt + 1, now.wall + 1 });
			}

			if (visited[next_x][next_y][now.wall] == 0 && total_map[next_x][next_y] == 48) {
				if (dp[next_x][next_y][now.wall] <= now.cnt + 1) continue;
				visited[next_x][next_y][now.wall] = 1;
				dp[next_x][next_y][now.wall] = now.cnt + 1;
				q.push({ next_x, next_y, now.cnt + 1, now.wall });
			}
		}
	}

	int answer = INF;

	for (int i = 0; i <= k; i++) {
		answer = (dp[n - 1][m - 1][i] != INF) ? min(answer, dp[n - 1][m - 1][i]) : answer;
	}
	if (answer == INF) answer = -1;

	cout << answer;
	return 0;
}