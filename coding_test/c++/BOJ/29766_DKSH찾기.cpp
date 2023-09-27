#include<iostream>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string input;

	cin >> input;

	int answer = 0;
	for (int i = 0; i < input.length() - 3; i++) {
		if (input.substr(i, 4) == "DKSH") {
			answer++;
		}
	}

	cout << answer;
	return 0;
}