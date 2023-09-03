#include<iostream>
#include<map>

using namespace std;

long long n, p, q;
map<long long, long long>dp;

long long make_num(long long a) {
	if (dp.count(a)) return dp[a];
	else {
		long long ls = a / p;
		long long rs = a / q;
		return dp[a] = make_num(ls) + make_num(rs);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> p >> q;

	dp[0] = 1;
	cout << make_num(n);

	return 0;
}