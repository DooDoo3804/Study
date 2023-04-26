#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

char total_map[5][5];
int moves[2][2] = {{0, 1}, {1, 0}};
int n;
int max_result = -100000000;
int min_result = 100000000;

stack<stack<char>> results;

void dfs(int a, int b, int sub_r)
{
    if (a == n - 1 && b == n - 1)
    {
        max_result = max(max_result, sub_r);
        min_result = min(min_result, sub_r);
        return;
    }
    for (auto m : moves)
    {
        int n_i = a + m[0];
        int n_j = b + m[1];
        int n_r = sub_r;
        if (n_i < n && n_j < n)
        {
            if (total_map[a][b] == '+')
                n_r += total_map[n_i][n_j] - '0';
            else if (total_map[a][b] == '-')
                n_r -= total_map[n_i][n_j] - '0';
            else if (total_map[a][b] == '*')
                n_r *= total_map[n_i][n_j] - '0';
            dfs(n_i, n_j, n_r);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> total_map[i][j];
        }
    }

    int player[2] = {0};

    dfs(player[0], player[1], total_map[0][0] - '0');

    cout << max_result << " " << min_result;

    return 0;
}