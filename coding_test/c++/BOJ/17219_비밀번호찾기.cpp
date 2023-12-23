#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	map<string, string> q;

	for (int i = 0; i < n; i++) {
		string site, pwd;
		cin >> site >> pwd;
		q.insert({ site, pwd });
	}

	for (int i = 0; i < m; i++) {
		string input;
		cin >> input;
		cout << q[input] << '\n';
	}

	return 0;
}