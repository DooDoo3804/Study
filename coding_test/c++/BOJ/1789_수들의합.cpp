#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long s;
	cin >> s;

	long long sum_nums = 0;
	long long n = 0;
	
	while (s - sum_nums > n) {
		n++;
		sum_nums += n;
	}

	cout << n;
	return 0;
}