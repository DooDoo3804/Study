#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int n, m, answer;
int total_map[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> q;
int moves[4][2] = { {1,0},{-1, 0}, {0,1}, {0, -1} };

void rot_tmt() {
	queue<pair<int, int>> sub_q;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (auto move : moves) {
			int next_x = now.first + move[0];
			int next_y = now.second + move[1];
			if (next_x < 0 || n <= next_x || next_y < 0 || m <= next_y) continue;
			if (total_map[next_x][next_y] == 0 && visited[next_x][next_y] == 0) {
				visited[next_x][next_y] = 1;
				total_map[next_x][next_y] = 1;
				sub_q.push(make_pair(next_x, next_y));
			}
		}
	}
	if (sub_q.empty()) answer--;
	q = sub_q;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> total_map[i][j];
			if (total_map[i][j] == 1) q.push(make_pair(i, j));
		}
	}
	
	while (!q.empty()) {
		rot_tmt();
		answer++;
	}

	bool check = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (total_map[i][j] == 0) check = false;
		}
	}

	if (check) cout << answer;
	else cout << -1;

	return 0;
}