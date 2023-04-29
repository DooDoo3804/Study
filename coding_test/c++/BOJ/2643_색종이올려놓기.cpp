#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define INF 999999999;

using namespace std;

struct page
{
    int x, y;
};

bool comp(page a, page b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x > b.x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dp[200][3] = {0};

    int n = 0;
    cin >> n;
    vector<page> pages;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            pages.push_back({a, b});
        }
        else
            pages.push_back({b, a});
    }

    sort(pages.begin(), pages.end(), comp);
    dp[0][0] = INF;
    dp[0][1] = INF;
    dp[0][2] = 0;

    int ans = 0;

    for (int i = 1; i < pages.size() + 1; i++)
    {
        dp[i][0] = pages[i - 1].x;
        dp[i][1] = pages[i - 1].y;

        for (int j = 0; j < i; j++)
        {
            if (pages[i - 1].x <= dp[j][0] && pages[i - 1].y <= dp[j][1] && dp[i][2] < dp[j][2] + 1)
            {
                dp[i][2] = dp[j][2] + 1;
            }
        }
        ans = max(ans, dp[i][2]);
    }
    cout << ans;
    return 0;
}