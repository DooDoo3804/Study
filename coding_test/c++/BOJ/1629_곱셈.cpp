#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector <long long> mul_nums;

	long long a;
	long long  b;
	long long c;
	cin >> a >> b >> c;

	long long sub_sum = a % c;
	int answer = 1;
	while (b) {
		if (b % 2 == 1) {
			answer = (answer * sub_sum) % c;
		}
		sub_sum = (sub_sum * sub_sum) % c;
		b /= 2;
	}

	cout << answer;
	return 0;
}