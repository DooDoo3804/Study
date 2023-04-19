#include <iostream>
#include <map>
#include <algorithm>

#define INF 999999999

using namespace std;

map<int, int> nums;

int get_ans(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;

    int total_num[1000001] = {0};
    int dp[1000001][3][2];
    // 모든 수 , 앞에서 빠진것과 나, 나를 뺀 것
    fill(dp[0], dp[1000001], INF);

    for (int i = 1; i < n; i++)
    {
        int now;
        cin >> now;
        if (i == 0)
        {
            dp[i][0][0] = now;
            dp[i][0][1] = 0;
            dp[i][1][0] = 0;
            dp[i][1][1] = 0;
            dp[i][2][0] = 0;
            dp[i][2][1] = i;
        }
        else
        {
            dp[i][0] = get_ans(dp[i - 1][0], now);
            dp[i][1] = max(get_ans(dp[i - 1][1], now), get_ans(dp[i - 1][2], now));
            dp[i][2] = dp[i - 1][0];
        }
    }

    return 0;
}