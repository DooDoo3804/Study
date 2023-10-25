#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>

using namespace std;

int total_map[129][129], visited[129][129], cnt[2];

void check_paper(int x, int y, int sub_n) {
	int color = total_map[x][y];
	bool check = true;
	for (int i = x; i < x + sub_n; i++) {
		for (int j = y; j < y + sub_n; j++) {
			if (visited[i][j] == 1) check = false;
			if (visited[i][j] == 0 && total_map[i][j] != color) check = false;
		}
	}
	if (!check) return;

	for (int i = x; i < x + sub_n; i++) {
		for (int j = y; j < y + sub_n; j++) {
			visited[i][j] = 1;
		}
	}
	cnt[color]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, sub_n;
	cin >> n;
	sub_n = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> total_map[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		while (sub_n) {
			for (int x = 0; x < n; x += sub_n) {
				for (int y = 0; y < n; y += sub_n) {
					if (visited[x][y] == 0) {
						check_paper(x, y, sub_n);
					}
				}
			}
			sub_n /= 2;
		}
	}

	cout << cnt[0] << '\n' << cnt[1];
	return 0;
}