#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

char total_map[20][20];
int moves[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int visited[26];
vector<char> now;
int ans; int r; int c;

void dfs(int a, int b) {
	if (now.size() > ans) {
		ans = now.size();
	}
	for (int i = 0; i < 4; i++) {
		int next_a = a + moves[i][0];
		int next_b = b + moves[i][1];
		if (0 <= next_a && next_a < r && 0 <= next_b && next_b < c) {
			if (visited[total_map[next_a][next_b] - 'A'] == 1) continue;
			else {
				now.push_back(total_map[next_a][next_b]);
				visited[total_map[next_a][next_b] - 'A'] = 1;

				dfs(next_a, next_b);

				visited[total_map[next_a][next_b] - 'A'] = 0;
				now.pop_back();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < c; j++) {
			total_map[i][j] = input[j];
		}
	}
	
	now.push_back(total_map[0][0]);
	visited[total_map[0][0] - 'A'] = 1;
	dfs(0, 0);

	cout << ans;

	return 0;
}