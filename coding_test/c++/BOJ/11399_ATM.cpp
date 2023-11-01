#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> times;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		times.push_back(input);
	}
	sort(times.begin(), times.end());

	int time = 0;
	for (int i = 0; i < n; i++) {
		time += (n - i) * times[i];
	}
	cout << time;
	return 0;
}