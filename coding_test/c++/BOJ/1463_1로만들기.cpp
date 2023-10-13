#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int ans[1000001];
	fill(ans, ans + 1000001, 2134567890);
	ans[0] = ans[1] = 0;

	for (int i = 0; i < 1000001; i++) {
		if (i + 1 <= 1000000) ans[i + 1] = min(ans[i + 1], ans[i] + 1);
		if (i * 2 <= 1000000) ans[i * 2] = min(ans[i * 2], ans[i] + 1);
		if (i * 3 <= 1000000) ans[i * 3] = min(ans[i * 3], ans[i] + 1);
	}
	cout << ans[n];


	return 0;
}