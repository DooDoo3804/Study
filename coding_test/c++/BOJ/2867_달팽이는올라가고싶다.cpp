#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a; int b; int v;
	cin >> a >> b >> v;
	int ans = (v - a) / (a - b);
	if ((v - a) % (a - b)) ans += 2;
	else ans += 1;

	cout << ans;

	return 0;
}