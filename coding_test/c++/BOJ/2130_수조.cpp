#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long A_perH[1040001] = { 0 };
	int min_h = 1000001;
	int max_h = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int b; int h; int w; int d;
		cin >> b >> h >> w >> d;
		for (int j = b; j < b + h; j++) {
			A_perH[j] += w * d;
		}
		min_h = min(min_h, b);
		max_h = max(max_h, b+h);
	}

	long long v;
	cin >> v;

	double ans = -1;

	for (int i = min_h; i < max_h; i++) {
		if (v - A_perH[i] > 0) {
			v -= A_perH[i];
		}
		else {
			ans = i;
			break;
		}
	}
	if (ans == -1) {
		cout << "OVERFLOW";
		return 0;
	}

	ans += (double) v / A_perH[int(ans)];

	cout.precision(2);
	cout << fixed << ans;
	return 0;
}