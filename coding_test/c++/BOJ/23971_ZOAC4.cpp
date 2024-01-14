#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int h, w, n, m;
	cin >> h >> w >> n >> m;

	int v_cnt = (h % (n + 1) == 0) ? h / (n + 1) : h / (n + 1) + 1;
	int h_cnt = (w % (m + 1) == 0) ? w / (m + 1) : w / (m + 1) + 1;

	cout << v_cnt * h_cnt;

	return 0;
}