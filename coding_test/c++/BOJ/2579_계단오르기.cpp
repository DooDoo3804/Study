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

	int scores[301] = { 0 };
	for (int i = 1; i <= n; i++) cin >> scores[i];

	int stairs[301][2] = {0};
	stairs[1][0] = scores[1];

	for (int i = 2; i <= n; i++) {
		stairs[i][0] = max(stairs[i][1], max(stairs[i - 2][0] + scores[i], stairs[i - 2][1] + scores[i]));
		stairs[i][1] = max(stairs[i][1], stairs[i - 1][0] + scores[i]);
	}

	cout << max(stairs[n][0], stairs[n][1]);
	return 0;
}