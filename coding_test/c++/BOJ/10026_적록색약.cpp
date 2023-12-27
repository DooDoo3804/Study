#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

char total_map[101][101];
int check[101][101];
int moves[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void BFS(int i, int j, int a, int n, char c) {

	for (auto move : moves) {
		int next_i = i + move[0];
		int next_j = j + move[1];
		if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n) continue;
		if (check[next_i][next_j] != 0) continue;
		if (c != total_map[next_i][next_j]) continue;
		check[next_i][next_j] = a;
		BFS(next_i, next_j, a, n, c);
	}
}

void BFS2(int i, int j, int a, int n, char c) {
	for (auto move : moves) {
		int next_i = i + move[0];
		int next_j = j + move[1];
		if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= n) continue;
		if (check[next_i][next_j] != 0) continue;
		if (c == 'R' || c == 'G') {
			if (total_map[next_i][next_j] == 'B') continue;
		}
		else if (c == 'B' && total_map[next_i][next_j] != c) continue;
		check[next_i][next_j] = a;
		BFS2(next_i, next_j, a, n, c);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 101; i++) fill(total_map[i], total_map[i] + 101, '.');

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < n; j++) {
			total_map[i][j] = input[j];
		}
	}
	int area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (total_map[i][j] != '.' && check[i][j] == 0) {
				area++;
				check[i][j] = area;
				BFS(i, j, area, n, total_map[i][j]);
			}
		}
	}
	cout << area << ' ';

	for (int i = 0; i < n; i++) fill(check[i], check[i] + 101, 0);

	area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (total_map[i][j] != '.' && check[i][j] == 0) {
				area++;
				check[i][j] = area;
				BFS2(i, j, area, n, total_map[i][j]);
			}

		}
	}

	cout << area;
	return 0;
}