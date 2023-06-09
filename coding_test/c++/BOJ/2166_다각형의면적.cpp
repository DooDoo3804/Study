#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> x_coord;
	vector<long long> y_coord;

	for (int i = 0; i < n; i++) {
		int x; int y;
		cin >> x >> y;
		x_coord.push_back(x);
		y_coord.push_back(y);
	}

	long long R = 0;
	long long L = 0;
	double ans = 0;
	cout.setf(ios::fixed);
	cout.precision(1);

	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			R += x_coord[i] * y_coord[0];
			L += y_coord[i] * x_coord[0];
		}
		else {
			R += x_coord[i] * y_coord[i + 1];
			L += y_coord[i] * x_coord[i + 1];
		}
	}
	ans = round(abs(L - R)) / 2;

	cout << ans;
	return 0;
}
