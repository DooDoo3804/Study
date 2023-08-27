#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int line_up[11] = { 0 };
int answer = 0;

void make_line_up(vector<vector<int>> &entry, int num) {
	if (num == 11) {
		int sub_sum = 0;
		for (int jj = 0; jj < 11; jj++) sub_sum += line_up[jj];
		answer = max(answer, sub_sum);
		return;
	}

	for (int ii = 0; ii < 11; ii++) {
		if (entry[num][ii] != 0 && line_up[ii] == 0) {
			line_up[ii] = entry[num][ii];
			make_line_up(entry, num + 1);
			line_up[ii] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c;
	cin >> c;

	vector<vector<int>> entry;
	vector<int> person_st;

	for (int i = 0; i < c; i++) {
		entry = vector<vector<int>>();
		fill(line_up, line_up + 11, 0);
		answer = 0;

		for (int j = 0; j < 11; j++) {
			person_st = vector<int>();
			for (int k = 0; k < 11; k++) {
				int st;
				cin >> st;
				person_st.push_back(st);
			}
			entry.push_back(person_st);
		}

		make_line_up(entry, 0);
		cout << answer << "\n";
	}

	return 0;
}