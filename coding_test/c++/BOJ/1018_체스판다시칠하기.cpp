#include <iostream>
#include <string>

using namespace std;

string chess_board[50];
int ans = 2134567890;

void check(int a, int b) {
	int sub_sum = 0;
	for (int i = a; i <  a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			if ((i + j) % 2 == 0 && chess_board[i][j] == 'W') {
				sub_sum++;
			}
			else if ((i + j) % 2 == 1 && chess_board[i][j] == 'B') {
				sub_sum++;
			}
			if (sub_sum > ans) {
				sub_sum = ans;
				break;
			}
		}
	}

	if (sub_sum < ans) ans = sub_sum;
	sub_sum = 0;

	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			if ((i + j) % 2 == 0 && chess_board[i][j] == 'B') {
				sub_sum++;
			}
			else if ((i + j) % 2 == 1 && chess_board[i][j] == 'W') {
				sub_sum++;
			}
			if (sub_sum > ans) {
				sub_sum = ans;
				break;
			}
		}
	}
	if (sub_sum < ans) ans = sub_sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; int m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> chess_board[i];
	}

	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			check(i, j);
		}
	}

	cout << ans;

	return 0;
}