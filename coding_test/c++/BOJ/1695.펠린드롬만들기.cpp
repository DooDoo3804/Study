#include <iostream>

using namespace std;

int nums[5001] = {0};
int result = 0;
int dp[5001][5001];

int pld(int s, int e)
{
    if (s >= e)
    {
        dp[s][e] = 0;
        return 0;
    }
    else if (dp[s][e] != -1)
        return dp[s][e];
    else if (nums[s] == nums[e])
    {
        return dp[s][e] = pld(s + 1, e - 1);
    }
    else
    {
        int rpld = 1 + pld(s + 1, e);
        int lpld = 1 + pld(s, e - 1);
        if (rpld > lpld)
            result = lpld;
        else
            result = rpld;
        dp[s][e] = result;
        return result;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;
    int start = 0;
    int end = n - 1;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    fill(dp[0], dp[5001], -1);

    cout << pld(start, end);
    return 0;
}