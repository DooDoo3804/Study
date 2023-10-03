#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	double w, h;
	cin >> w >> h;

	double answer = w * h / 2;

	cout << fixed;
	cout.precision(1);
	cout << answer;

	return 0;
}