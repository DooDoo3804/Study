#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a; int b; int c; int d; int e; int f;
	cin >> a >> b >> c >> d >> e >> f;

	int x = (b*f - c * e) / (b*d - a * e);
	int y = (b != 0) ? (c - a * x) / b : (f - d * x) / e;

	cout << x << " " << y;

	return 0;
}