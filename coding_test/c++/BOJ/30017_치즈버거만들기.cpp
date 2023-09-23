#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	int answer = 0;
	answer++;
	a--;

	while (a > 0 && b > 0) {
		a--;
		b--;
		answer += 2;
	}

	cout << answer;

	return 0;
}