#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int m;
    cin >> n >> m;

    while (n && m)
    {
        int total_map[1001][1001];
        fill(total_map[0], total_map[1001], 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int input;
                cin >> input;

                if (i == 0)
                    total_map[i][j] = input;
                else if (i != 0)
                {
                    if (input == 1)
                    {
                        if (total_map[i][j - 1] != 0)
                        {
                            total_map[i][j] = min(min(total_map[i - 1][j - 1], total_map[i - 1][j]), total_map[i][j - 1]) + 1;
                        }
                        else
                            total_map[i][j] = 1;
                    }
                }

                ans = max(ans, total_map[i][j]);
            }
        }
        cout << ans << "\n";
        cin >> n >> m;
    }

    return 0;
}
