#include <iostream>
#include <algorithm>

using namespace std;

int n;
int coupons;
int dp[101] = {0};

int npos_days[101] = {0};
int price_coupon[3][2] = {{10000, 0}, {25000, 1}, {37000, 2}};

void check_min(int i)
{
    if (i == n)
        return;
    else if (npos_days[i] == 1)
    {
        dp[i] = dp[i - 1];
        check_min(i + 1);
    }

    else
    {
        if (i < 3)
        {
            dp[i] = dp[i - 1] + price_coupon[0][0];
            check_min(i + 1);
        }
        else if (3 <= i && i < 5)
        {
            dp[i] = min((dp[i - 1] + price_coupon[0][0]), dp[i - 3] + price_coupon[1][0]);
            if (dp[i] == dp[i - 3] + price_coupon[1][0])
                coupons++;
            check_min(i + 1);
        }
        else
        {
            if (coupons >= 3)
            {
                coupons -= 3;
                dp[i] = dp[i - 1];
                check_min(i + 1);
            }
            else
            {
                dp[i] = min(dp[i], dp[i - 1] + price_coupon[0][0]);
                check_min(i + 1);
                dp[i] = min(dp[i], dp[i - 3] + price_coupon[1][0]);
                coupons++;
                check_min(i + 1);
                coupons--;
                dp[i] = min(dp[i], dp[i - 5] + price_coupon[2][0]);
                coupons += 2;
                check_min(i + 1);
                coupons += 2;
            }
        }
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

    fill(dp, dp + 102, 100000000);

    check_min(1);

    cout << dp[n];

    return 0;
}