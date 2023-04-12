#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string nums;
	int k = 0;
	cin >> nums >> k;
	

	vector <string> result;
	result.push_back(nums);

	queue <string> q;
	q.push(nums);

	for (int i = 0; i < k; i++) {
		result.clear();
		queue <string> qq;
		while (!q.empty()) {
			string sub_num = q.front();
			for (int a = 0; a < nums.size(); a++) {
				for (int b = nums.size() - 1; b > a; b--) {
					if (a == 0 && sub_num[b] == '0') continue;
					else {
						string ssub_num = sub_num;
						char sub_char = ssub_num[a];
						ssub_num[a] = ssub_num[b];
						ssub_num[b] = sub_char;
						if (!count(result.begin(), result.end(), ssub_num)) {
							result.push_back(ssub_num);
							qq.push(ssub_num);
						}
					}
				}
			}
			q.pop();
		}
		q = qq;
	}

	string output = "-1";
	while (!q.empty()) {
		output = max(output, q.front());
		q.pop();
	}
	cout << output;

	return 0;
}