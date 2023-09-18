#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int a_bikes[100] = { 0 };
	int answer = 0;

	for (int i = 0; i < n; i++) cin >> a_bikes[i];
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (input > a_bikes[i]) answer += input - a_bikes[i];
	}
	cout << answer;

	return 0;
}