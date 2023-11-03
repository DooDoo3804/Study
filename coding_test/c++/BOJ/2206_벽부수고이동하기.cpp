#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>

using namespace std;

int check[1001][1001][2];
char total_map[1001][1001];
int moves[4][2] = { {0,1}, {1,0}, {0, -1}, {-1,0} };

struct node {
	int x, y, wall;
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			total_map[i][j] = input[j];
			check[i][j][0] = check[i][j][1] = 2134567890;
		}
	}

	queue<node> q;

	q.push({ 0, 0, 0 });
	check[0][0][0] = check[0][0][1] = 1;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (auto move : moves) {
			int next_x = now.x + move[0];
			int next_y = now.y + move[1];

			if (0 > next_x || n <= next_x || 0 > next_y || m <= next_y) continue;

			if (total_map[next_x][next_y] == '1' && now.wall == 1) continue;

			if (total_map[next_x][next_y] == '0' && check[now.x][now.y][now.wall] + 1 < check[next_x][next_y][now.wall]) {
				q.push({ next_x, next_y, now.wall });
				check[next_x][next_y][now.wall] = check[now.x][now.y][now.wall] + 1;
			}

			else if (total_map[next_x][next_y] == '1' && now.wall == 0 && check[now.x][now.y][now.wall] + 1 < check[next_x][next_y][1]) {
				q.push({ next_x, next_y, 1 });
				check[next_x][next_y][1] = check[now.x][now.y][now.wall] + 1;
			}
		}
	}
	int answer = min(check[n - 1][m - 1][0], check[n - 1][m - 1][1]);
	answer = (answer == 2134567890) ? -1 : answer;
	cout << answer;

	return 0;
}