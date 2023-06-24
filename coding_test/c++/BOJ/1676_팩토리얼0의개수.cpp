#include <iostream>
#include <algorithm>	
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int ans[2] = { 0 };

	for (int i = 1; i <= n; i++) {
		int now_num = i;
		while (true) {
			if (now_num % 10 == 0) {
				now_num /= 10;
				ans[0] += 1;
				ans[1] += 1;
			}
			else if (now_num % 2 == 0) {
				now_num /= 2;
				ans[0] += 1;
			}
			else if (now_num % 5 == 0) {
				now_num /= 5;
				ans[1] += 1;
			}
			else {
				break;
			}
		}
	}

	cout << min(ans[0], ans[1]);

	return 0;
}
