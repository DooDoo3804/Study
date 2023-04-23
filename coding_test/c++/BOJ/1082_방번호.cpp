#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
	return a[1] < b[1];
}

bool comp_str(string a, string b)
{
	if (a.size() == b.size())
		return a > b;
	else if (a.size() != b.size() && a[0] != '0' && b[0] != '0')
		return a.size() > b.size();
	else return a > b;
}

bool comp_sum(char a, char b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int>> num_price;

	int n;
	cin >> n;

	int c = 0;

	map<char, int> nums_price;

	for (int i = 0; i < n; i++)
	{
		vector<int> sub_vec;
		int a;
		cin >> a;
		sub_vec.push_back(c);
		sub_vec.push_back(a);
		num_price.push_back(sub_vec);
		c++;
	}
	int m;
	cin >> m;

	sort(num_price.begin(), num_price.end(), compare);

	for (auto np : num_price)
	{
		nums_price[(char) np[0]] = np[1];
	}

	string dp[51];

	for (int i = 1; i < m + 1; i++)
	{
		vector<string> sub_str;
		for (auto price : num_price)
		{
			int p = price[1];
			if (i - p >= 0)
			{
				string sub = dp[i - p] + to_string(price[0]);
				sort(sub.begin(), sub.end(), comp_sum);
				int pp = 0;
				for (char c : sub)
				{
					pp += nums_price[c];
				}
				if (pp <= m)
					sub_str.push_back(sub);
			}
		}
		if (sub_str.empty())
			dp[i] = dp[i - 1];
		else
		{
			sort(sub_str.begin(), sub_str.end(), comp_str);
			dp[i] = sub_str.front();
		}
	}
	if (dp[m][0] == '0') cout << 0;
	else cout << dp[m];
	return 0;
}
