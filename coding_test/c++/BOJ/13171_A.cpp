#include <iostream>
#include <vector>

using namespace std;

vector<int> bi_num;

void make_bi(long long num) {
	while (num) {
		if (num % 2) bi_num.push_back(1);
		else bi_num.push_back(0);
		num /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector <long long> mul_nums;

	long long a;
	long long  x;
	cin >> a >> x;
	long long index = 1;
	while (index <= x) {
		if (index == 1) mul_nums.push_back(a % 1000000007); 
		else mul_nums.push_back((mul_nums.back() * mul_nums.back()) % 1000000007);
		index *= 2;
	}

	make_bi(x);

	int answer = 1;


	for (int i = 0; i < bi_num.size(); i++) {
		if (bi_num[i]) answer = (answer * mul_nums[i]) % 1000000007;
	}

	cout << answer;
	return 0;
}