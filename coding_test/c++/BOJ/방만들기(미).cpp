#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool compare(vector<char> a, vector<char> b)
{
	return a[1] < b[1];
}

bool comp_str(string a, string b)
{
	if (a.size() == b.size())
		return a > b;
	else if (a.size() != b.size())
		return a.size() > b.size();
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

	vector<vector<string>> num_price;

	int n;
	cin >> n;

	string c = "0";

	map<char, int> nums_price;

	for (int i = 0; i < n; i++)
	{
		vector<char> sub_vec;
		string a;
		cin >> a;
		sub_vec.push_back(c);
		sub_vec.push_back(a);
		num_price.push_back(sub_vec);
		c += 1;
	}
	int m;
	cin >> m;

	sort(num_price.begin(), num_price.end(), compare);

	for (auto np : num_price)
	{
		nums_price[np[0]] = stoi(np[1]);
	}

	string dp[51];

	for (int i = 1; i < m + 1; i++)
	{
		vector<string> sub_str;
		for (auto price : num_price)
		{
			int p = (stoi(price[1]));
			char num = stoi(price[0]);
			if (i - p >= 0)
			{
				string sub = dp[i - p] + num;
				sort(sub.begin(), sub.end(), comp_sum);
				int pp = 0;
				for (auto c : sub)
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
	cout << dp[m];
	return 0;
}
