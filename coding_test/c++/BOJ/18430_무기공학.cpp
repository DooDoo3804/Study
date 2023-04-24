#include <iostream>

using namespace std;

int n = 0;
int m = 0;
int check_map[5][5] = {0};
int result = 0;
int out_result = 0;
int boomrs[4][2][2] = {{{0, -1}, {1, 0}}, {{0, -1}, {-1, 0}}, {{0, 1}, {1, 0}}, {{0, 1}, {-1, 0}}};
int total_map[5][5] = {0};

void make_boo(int i)
{
    for (int nn = i; nn < n * m; nn++)
    {
        int ii = nn / m;
        int jj = nn % m;
        if (check_map[ii][jj] == 0)
        {
            for (int b = 0; b < 4; b++)
            {
                int n_p = ii + boomrs[b][0][0];
                int n_q = jj + boomrs[b][0][1];
                int n_pp = ii + boomrs[b][1][0];
                int n_qq = jj + boomrs[b][1][1];
                if (n_p >= 0 && n_p < n && n_q >= 0 && n_q < m && check_map[n_p][n_q] == 0 &&
                    n_pp >= 0 && n_pp < n && n_qq >= 0 && n_qq < m && check_map[n_pp][n_qq] == 0)
                {
                    check_map[ii][jj] = 1;
                    check_map[n_p][n_q] = 1;
                    check_map[n_pp][n_qq] = 1;
                    result += (total_map[ii][jj] * 2 + total_map[n_p][n_q] + total_map[n_pp][n_qq]);

                    if (out_result < result)
                        out_result = result;
                    make_boo(nn);
                    result -= (total_map[ii][jj] * 2 + total_map[n_p][n_q] + total_map[n_pp][n_qq]);
                    check_map[ii][jj] = 0;
                    check_map[n_p][n_q] = 0;
                    check_map[n_pp][n_qq] = 0;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> total_map[i][j];
        }
    }

    make_boo(0);
    cout << out_result;
    return 0;
}