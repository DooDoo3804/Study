#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= 1000000; i++) {
		int num = i;
		int ans = i;
		int now_num = i;
		while (num > 0) {
			now_num += num % 10;
			num /= 10;
		}
		if (now_num == n) {
			cout << ans;
			return 0;
		}
	}

	cout << 0;
	return 0;
}