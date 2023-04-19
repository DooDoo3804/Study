#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;
    long long dp[100001][3] = {0};
    long long max_num = 10000000000;

    for (int i = 1; i < n + 1; i++)
    {
        long long x = 0;
        long long p = 0;

        cin >> x >> p;
        if (dp[i - 1][0] == max_num)
            dp[i][0] = max_num;
        else if (dp[i - 1][0] <= x)
            dp[i][0] = dp[i - 1][0] + p;
        else if (dp[i - 1][0] > x)
            dp[i][0] = max_num;

        dp[i][2] = dp[i - 1][0];

        if (dp[i - 1][1] <= x && dp[i - 1][2] <= x)
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][2]) + p;
        else if (dp[i - 1][1] <= x && dp[i - 1][2] > x)
            dp[i][1] = dp[i - 1][1] + p;
        else if (dp[i - 1][1] > x && dp[i - 1][2] <= x)
            dp[i][1] = dp[i - 1][2] + p;
        else if (dp[i - 1][1] > x && dp[i - 1][2] > x)
            dp[i][1] = max_num;
    }

    for (auto a : dp[n])
    {
        if (a != max_num)
        {
            cout << "Kkeo-eok";
            return 0;
        }
    }
    cout << "Zzz";
    return 0;
}