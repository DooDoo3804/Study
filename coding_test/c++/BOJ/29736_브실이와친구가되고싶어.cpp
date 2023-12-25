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
	
	int answer = 0;
	string output = "IMPOSSIBLE";

	int a, b, k, x;
	cin >> a >> b >> k >> x;

	for (int i = a; i <= b; i++) {
		if (abs(i - k) <= x) answer++;
	}

	if (!answer) cout << output;
	else cout << answer;

	return 0;
}