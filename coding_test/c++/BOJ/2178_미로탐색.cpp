#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int moves[4][2] = { {0, 1}, {0, -1}, {1,0}, {-1,0} };
string total_map[101][101];
int visited[101][101];
int cnt, n, m;

void bfs() {
	queue<vector<int>> q;
	q.push({0,0,1});
	visited[0][0] = 1;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		if (now[0] == n - 1 && now[1] ==  m - 1) {
			cout << now[2];
			break;
		}
		for (auto move : moves) {
			int next_x = now[0] + move[0];
			int next_y = now[1]+ move[1];
			if (0 > next_x || n < next_x || 0 > next_y || m < next_y) continue;
			if (visited[next_x][next_y] == 0 && total_map[next_x][next_y] == "1") {
				q.push({ next_x, next_y, now[2] + 1 });
				visited[next_x][next_y] = 1;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			total_map[i][j] = input[j];
		}
	}
	bfs();

	return 0;
}