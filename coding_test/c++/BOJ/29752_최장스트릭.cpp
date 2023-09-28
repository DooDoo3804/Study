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
	int output = 0;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (input == 0) answer = 0;
		else {
			answer++;
			output = max(output, answer);
		}
	}
	cout << output;
	return 0;
}