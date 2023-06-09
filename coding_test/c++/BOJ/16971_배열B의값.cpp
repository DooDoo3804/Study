#include<iostream>
#include<algorithm>

using namespace std;

int n;
int m;
int total_map[1001][1001];
int ans;
int ref_sum;
int sub_sum;

// 가로 줄 교환
void v_find_sum(int x, int y) {
	sub_sum = ref_sum;
	for (int a = 0; a < m; a++) {
		if (a == 0 || a == m - 1) {
			sub_sum -= total_map[x][a] * 3;
			sub_sum -= total_map[y][a] * 3;
		}
		else {
			sub_sum -= total_map[x][a] * 2;
			sub_sum -= total_map[y][a] * 2;
		}
	}
	for (int a = 0; a < n; a++) {
		if (a != x && a != y) {
			sub_sum -= total_map[a][0] * 2;
			sub_sum -= total_map[a][m - 1] * 2;
		}
	}
	ans = max(ans, sub_sum);
}

// 세로 줄 교환
void h_find_sum(int x, int y) {
	sub_sum = ref_sum;
	for (int a = 0; a < n; a++) {
		if (a == 0 || a == n - 1) {
			sub_sum -= total_map[a][x] * 3;
			sub_sum -= total_map[a][y] * 3;
		}
		else {
			sub_sum -= total_map[a][x] * 2;
			sub_sum -= total_map[a][y] * 2;
		}
	}
	for (int a = 0; a < m; a++) {
		if (a != x && a != y) {
			sub_sum -= total_map[n - 1][a] * 2;
			sub_sum -= total_map[0][a] * 2;
		}
	}
	ans = max(ans, sub_sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> total_map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ref_sum += total_map[i][j] * 4;
			if (i == 0 || i == n - 1) {
				if (j == 0 || j == m - 1) {
					sub_sum += total_map[i][j];
				}
				else {
					sub_sum += total_map[i][j] * 2;
				}
			}
			else {
				if (j == 0 || j == m - 1) {
					sub_sum += total_map[i][j];
				}
				else {
					sub_sum += total_map[i][j] * 4;
				}
			}
		}
	}
	ans = sub_sum;

	for (int i = 0; i < n - 1; i++) {
		v_find_sum(0, n - 1 - i);
		v_find_sum(n - 1, i);
	}
	for (int i = 0; i < m - 1; i++) {
		h_find_sum(0, m - 1 - i);
		h_find_sum(m - 1, i);
	}

	cout << ans;

	return 0;
}
