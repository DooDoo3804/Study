#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

char check[5] = { 'a', 'e', 'i', 'o', 'u' };
vector<char> list;
vector<char> answer;

void make_pwd(int l, int a, int cnt, int c) {
	
	if (l == 0) {
		if (a >= 1 && answer.size() - a >= 2) {
			for (char ans : answer) cout << ans;
			cout << '\n';
		}
		else return;
	}
	
	for (int i = cnt; i < c; i++) {
		
		answer.push_back(list[i]);
		if (find(check, check + 5, list[i]) != check + 5) {
			make_pwd(l - 1, a + 1, i + 1, c);
		}
		else make_pwd(l - 1, a, i + 1, c);

		answer.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int l; int c;
	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		char input;
		cin >> input;
		list.push_back(input);
	}

	sort(list.begin(), list.end());
	
	make_pwd(l, 0, 0, c);
	
	return 0;
}