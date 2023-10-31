#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int>coins;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		coins.push_back(input);
	}
	reverse(coins.begin(), coins.end());

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		cnt += k / coins[i];
		k %= coins[i];
	}

	cout << cnt;
	return 0;
}