#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;

	int max_ans = (n + m - 1) - (m * k);
	int min_ans = n - (m * k);
	
	min_ans = (min_ans < 0) ? 0 : min_ans;
	max_ans = (max_ans < 0) ? 0 : max_ans;
	cout << min_ans << " " << max_ans;

	return 0;
}