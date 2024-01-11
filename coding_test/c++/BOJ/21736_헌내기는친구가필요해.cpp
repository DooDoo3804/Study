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

	int n, m;
	cin >> n >> m;

	int total_map[601][601] = { 0 };
	int visited[601][601] = { 0 };
	int i_x = 0;
	int i_y = 0;
	int moves[4][2] = { {0,1}, {0, -1}, {1,0},{-1,0} };

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			total_map[i][j] = input[j];
			if (total_map[i][j] == 'I') {
				i_x = i;
				i_y = j;
			}
		}
	}



	queue<pair<int, int>> q;
	visited[i_x][i_y] = 1;
	q.push(make_pair(i_x, i_y));

	int answer = 0;

	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();

		for (auto move : moves) {
			int next_x = now_x + move[0];
			int next_y = now_y + move[1];

			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) continue;

			if (total_map[next_x][next_y] == 'X') continue;
			if (visited[next_x][next_y] == 1) continue;

			if (total_map[next_x][next_y] == 'P') answer++;

			q.push(make_pair(next_x, next_y));
			visited[next_x][next_y] = 1;
		}
	}

	if (answer == 0) cout << "TT";
	else cout << answer;

	return 0;
}