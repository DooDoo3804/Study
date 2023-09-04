#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct coord {
	int x, y;
};

int r, c, t;
int visited[50][50];
int total_map[50][50][2];
int moves[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
int move_air[8][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0}, {0, 1}, {1, 0}, {0, -1} , {-1, 0} };
vector<coord> air_con;
int answer = 0;

void air(int time) {
	int n = time % 2;
	for (int i = 0; i < 2; i++) {
		int pre = 0;
		coord now = (i == 0) ? air_con[0] : air_con[1];
		if (i == 0) {
			int next_x = now.x;
			int next_y = now.y;
			for (int j = 0; j < 4; j++) {
				if (total_map[next_x + move_air[j][0]][next_y + move_air[j][1]][n] == -1) continue;
				while (0 <= next_x + move_air[j][0] && next_x + move_air[j][0] < r && 0 <= next_y + move_air[j][1] && next_y + move_air[j][1] < c) {
					int sub = pre;
					pre = (total_map[next_x][next_y][n] == -1) ? 0 : total_map[next_x][next_y][n];
					total_map[next_x][next_y][n] = (total_map[next_x][next_y][n] == -1) ? -1 : sub;
					next_x += move_air[j][0];
					next_y += move_air[j][1];
					if (total_map[next_x][next_y][n] == -1) break;
				} ;
			}
		}
		else {
			int next_x = now.x;
			int next_y = now.y;
			for (int j = 4; j < 8; j++) {
				if (total_map[next_x + move_air[j][0]][next_y + move_air[j][1]][n] == -1) continue;
				while (0 <= next_x + move_air[j][0] && next_x + move_air[j][0] < r && 0 <= next_y + move_air[j][1] && next_y + move_air[j][1] < c) {
					int sub = pre;
					pre = (total_map[next_x][next_y][n] == -1) ? 0 : total_map[next_x][next_y][n];
					total_map[next_x][next_y][n] = (total_map[next_x][next_y][n] == -1) ? -1 : sub;
					next_x += move_air[j][0];
					next_y += move_air[j][1];
					if (total_map[next_x][next_y][n] == -1) break;
				};
			}
		}
	}
}

void spread(int time) {
	int n = time % 2;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (total_map[i][j][!n] == -1) {
				total_map[i][j][n] = -1;
				continue;
			}
			int sub_sum = 0;
			int cnt = 0;
			for (auto move : moves) {
				if (0 <= i + move[0] && i + move[0] < r && 0 <= j + move[1] && j + move[1] < c) {
					if (total_map[i + move[0]][j + move[1]][!n] == -1) continue;
					sub_sum += total_map[i + move[0]][j + move[1]][!n] / 5;
					cnt++;
				}
			}
			total_map[i][j][n] = sub_sum + (total_map[i][j][!n] - (total_map[i][j][!n] / 5 * cnt));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> total_map[i][j][0];
			if (total_map[i][j][0] == -1) air_con.push_back({ i, j });
		}
	}
	
	for (int i = 1; i <= t; i ++) {
		answer = 0;
		spread(i);
		air(i);
	}

	for (int j = 0; j < r; j++) {
		for (int k = 0; k < c; k++) {
			answer += (total_map[j][k][t%2] != -1) ? total_map[j][k][t % 2] : 0;
		}
	}
	
	cout << answer;

	return 0;
}