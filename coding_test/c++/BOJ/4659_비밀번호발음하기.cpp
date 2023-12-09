#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;

	char check[5] = { 'a', 'e', 'i', 'o', 'u' };

	bool answer = true;

	int check_1 = 0;
	int check_2 = 0;
	char check_3 = ' ';

	while (input != "end") {
		string output = "<";
		output += input;
		output += "> is ";

		answer = true;
		check_1 = check_2 = 0;
		check_3 = ' ';

		for (char s : input) {
			if (s != 'e' && s != 'o' && check_3 == s) answer = false;
			if (find(check, check + 5, s) != check + 5) {
				if (check_1 == 0) check_1 = 1;
				if (find(check, check + 5, check_3) == check + 5) {
					check_2 = 0;
				}
				check_2++;
			}
			else {
				if (find(check, check + 5, check_3) != check + 5) {
					check_2 = 0;
				}
				check_2++;
			}
			check_3 = s;
			if (check_2 >= 3) {
				answer = false;
				break;
			}
		}

		if (check_1 == 0) answer = false;

		if (!answer) output += "not ";
		output += "acceptable.";
		cout << output << '\n';
		cin >> input;
	}

	return 0;
}