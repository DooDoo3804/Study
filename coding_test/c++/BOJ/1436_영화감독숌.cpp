#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
#include<cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int cnt = 0;
	int temp = 665;

	while (cnt != n) {
		temp++;
		int num = temp;
		while (num != 0) {
			if (num % 1000 == 666) {
				cnt++;
				break;
			}
			num /= 10;
		}
	}
	
	cout << temp;

	return 0;
}