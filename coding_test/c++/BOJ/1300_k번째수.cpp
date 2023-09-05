#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n, k;
	cin >> n >> k;

	long long low = 1;
	long long high = pow(n, 2);

	while (low <= high) {
		long long mid = (low + high) / 2;

		long long cnt = 0;
		for (int i = 1; i < n + 1; i++) {
			cnt += min(mid / i, n);
		}

		if (cnt < k) low = mid + 1;
		else high = mid - 1;
	}

	cout << low;

	return 0;
}