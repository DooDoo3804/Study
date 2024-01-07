#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int n;
int total_map[26][26];
int visited[26][26];
int moves[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int blocks;

void dfs(int x, int y) {

	for (auto move : moves) {
		int next_x = x + move[0];
		int next_y = y + move[1];

		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n) continue;

		if (total_map[next_x][next_y] == 0) continue;

		if (total_map[next_x][next_y] == 1 && visited[next_x][next_y] == 0) {
			visited[next_x][next_y] = 1;
			dfs(next_x, next_y);
			blocks++;
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < n; j++) {
			total_map[i][j] = input[j] - '0';
		}
		
	}

	int cnt = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (total_map[i][j] == 1 && visited[i][j] == 0) {
				blocks = 1;
				visited[i][j] = 1;
				dfs(i, j);
				pq.push(blocks);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
	while (!pq.empty()) {
		int output = pq.top();
		pq.pop();
		cout << output << '\n';
	}

	return 0;
}