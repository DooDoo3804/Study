#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct point{
	int x; int y; int count;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; int m;
	cin >> n >> m;

	int total_map[500][500] = { 0 };
	int counts[1001] = { 0 };

	int now_x; int now_y;
	cin >> now_x >> now_y;
	int index = -1;

	for (int i = 0; i < m; i++) {
		int x; int y;
		cin >> x >> y;
		total_map[x - 1][y - 1] = index;
		index--;
	}

	int moves[8][2] = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1,2}, {2, -1}, {2, 1} };

	queue<point> q;
	q.push({ now_x - 1, now_y - 1, 0 });

	while (!q.empty()) {
		point now = q.front();
		q.pop();
		for (auto move : moves) {
			int next_x = now.x + move[0];
			int next_y = now.y + move[1];
			if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n) {
				if (total_map[next_x][next_y] == 0) {
					total_map[next_x][next_y] = now.count + 1;
					q.push({ next_x, next_y, now.count + 1});
				}
				else if (total_map[next_x][next_y] < 0) {
					int idx = -total_map[next_x][next_y];
					counts[idx] = now.count + 1;
					total_map[next_x][next_y] = now.count + 1;
					q.push({ next_x, next_y, now.count + 1 });
				}
			}
		}
	}

	for (int i = 1; i < m + 1; i++) {
		cout << counts[i] << " ";
	}

	return 0;
}