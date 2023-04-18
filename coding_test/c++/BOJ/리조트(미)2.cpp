#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[101][2] = {0};

int npos_days[101] = {0};
int price_coupon[3][3] = {{10000, 0}, {25000, 1}, {37000, 2}};

int check_min(int day, int coupon)
{

    if (day == n + 1)
        return 0;
    else if (npos_days[day] == 0)
    {
        if (dp[day][coupon] != 100000000)
            return dp[day][coupon];
        else if ()
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int input_num = 0;
        cin >> input_num;
        npos_days[input_num] = 1;
    }

    fill(dp[0], dp[101], 100000000);

    check_min(1, 0);

    cout << dp[n];

    return 0;
}