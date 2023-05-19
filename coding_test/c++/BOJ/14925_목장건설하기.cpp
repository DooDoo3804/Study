#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    int n;
    cin >> m >> n;
    int total_map[1001][1001];
    fill(total_map[0], total_map[1001], 0);
    int ans = 0;
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            int status = 0;
            cin >> status;
            if (status == 1 || status == 2)
            {
                total_map[i][j] = 0;
            }
            else
            {
                total_map[i][j] = min(total_map[i][j - 1], min(total_map[i - 1][j - 1], total_map[i - 1][j])) + 1;
            }
            ans = max(ans, total_map[i][j]);
        }
    }
    cout << ans;

    return 0;
}
