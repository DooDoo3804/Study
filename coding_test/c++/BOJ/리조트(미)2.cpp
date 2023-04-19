#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n;
int dp[101][5];
map<int, int> npos_day;

int find_min(int day, int coupon)
{
    if (day >= n)
        return 0;
    else if (dp[day][coupon] != 1000000000)
        return dp[day][coupon];
    else if (npos_day[day] == 1)
        return 0;
    else
    {
        int now = dp[day][coupon];
        now = min(now, find_min(day + 1, coupon) + 10000);
        now = min(now, find_min(day + 3, coupon + 1) + 25000);
        now = min(now, find_min(day + 5, coupon + 2) + 37000);
        if (coupon >= 3)
            now = min(now, find_min(day + 1, coupon - 3));
        return dp[day][coupon] = now;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> n >> m;

    fill(dp[0], dp[101], 1000000000);

    for (int i = 0; i < m; i++)
    {
        int j;
        cin >> j;
        npos_day[j] = 1;
    }

    find_min(1, 0);

    return 0;
}
