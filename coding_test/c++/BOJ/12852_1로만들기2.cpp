#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 999999999

bool comp(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int dp[1000001];
    vector<int> dp_sub[1000001];

    dp[1] = 0;
    dp[1] = {1};
    dp_sub[1] = {1};

    for (int i = 2; i < n + 1; i++)
    {
        vector<int> sub_vector = dp_sub[i - 1];
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i])
        {
            dp[i] = dp[i / 3] + 1;
            sub_vector = dp_sub[i / 3];
        }
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i])
        {
            dp[i] = dp[i / 2] + 1;
            sub_vector = dp_sub[i / 2];
        }
        sub_vector.push_back(i);
        dp_sub[i] = sub_vector;
    }

    cout << dp_sub[n].size() - 1 << "\n";

    sort(dp_sub[n].begin(), dp_sub[n].end(), comp);

    for (auto a : dp_sub[n])
    {
        cout << a << " ";
    }
    return 0;
}
