#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int imp[10] = { 0 };
	queue<int> q;
	queue<int> iq;
	int cnt;

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		fill(imp, imp + 10, 0);
		q = queue<int>();
		iq = queue<int>();
		cnt = 0;

		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			q.push(input);
			iq.push(i);
			imp[input]++;
		}

		while (!q.empty()) {
			int now_num = q.front();
			int now_index = iq.front();
			q.pop();
			iq.pop();
			bool check = true;

			for (int i = 9; i > now_num; i--) {
				if (imp[i] == 0) continue;
				check = false;
				q.push(now_num);
				iq.push(now_index);
				break;
			}

			if (check == false) continue;

			imp[now_num]--;
			cnt++;

			if (now_index == m) {
				cout << cnt << '\n';
				break;
			}
		}
	}
	return 0;
}