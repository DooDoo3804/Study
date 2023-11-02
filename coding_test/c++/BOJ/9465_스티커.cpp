#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>

using namespace std;

int check[2][100001][2];
int board[2][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, n;
	cin >> t;
	while (t--) {

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 100001; j++) {
				check[i][j][0] = check[i][j][1] = 0;
			}
		}
			
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {
			check[0][i][0] = max(max(check[1][i - 1][0], check[1][i - 1][1]), check[0][i - 1][1]) + board[0][i - 1];
			check[0][i][1] = check[1][i][1] = max(max(max(check[1][i - 1][0], check[1][i - 1][1]), check[0][i - 1][1]),check[0][i - 1][0]);
			check[1][i][0] = max(max(check[1][i - 1][1], check[0][i - 1][1]), check[0][i - 1][0]) + board[1][i - 1];
		}
		int answer = max(max(max(check[0][n][0], check[0][n][1]), check[1][n][0]), check[1][n][1]);
		cout << answer << '\n';
	}

	return 0;
}