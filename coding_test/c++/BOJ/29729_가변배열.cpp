#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int s, n, m;
	cin >> s >> n >> m;
	long long now_count = 0;
	long long max_len = s;

	for (int i = 0; i < n + m + 1; i++) {
		int cmd = 0;
		cin >> cmd;

		if (cmd == 0) {
			now_count--;
		}
		else {
			if (now_count == max_len) {
				max_len *= 2;
			}
			now_count++;
		}
	}
	
	cout << max_len;

	return 0;
}