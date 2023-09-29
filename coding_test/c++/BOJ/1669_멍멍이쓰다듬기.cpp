#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long x, y;
	cin >> x >> y;
	
	long long diff = y - x;
	long long sqrt_diff = sqrt(diff);

	long long answer = 0;

	if (x == y) {
		cout << 0;
		return 0;
	}

	if (sqrt_diff * sqrt_diff == diff) answer = 2 * sqrt_diff - 1;
	else if (sqrt_diff * (sqrt_diff + 1) >= diff) answer = 2 * sqrt_diff;
	else answer = 2 * sqrt_diff + 1;
	
	cout << answer;

	return 0;
}