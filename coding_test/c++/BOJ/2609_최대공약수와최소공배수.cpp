#include <iostream>

using namespace std;

int max_num(int a, int b) {
	int temp = 0;
	if (a < b) {
		temp = a;
		a = b;
		b = temp;
	}

	int n = 0;
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x;
	int y;
	cin >> x >> y;

	cout << max_num(x, y) << "\n";
	cout << x * y / max_num(x, y);

	return 0;
}