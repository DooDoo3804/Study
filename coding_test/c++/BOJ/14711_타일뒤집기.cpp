#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;
    int cross[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int count_map[1001][1001] = {0};
    vector<string> str_map;
    string input;
    cin >> input;
    str_map.push_back(input);

    for (int i = 1; i < n + 1; i++)
    {
        vector<int> index_list;
        string sub_str;
        for (int j = 0; j < n; j++)
        {
            if (str_map[i - 1][j] == '#')
            {
                index_list.push_back(j);
                count_map[i - 1][j]++;
            }
        }
        for (auto j : index_list)
        {
            for (auto c : cross)
            {
                int nxt_i = c[0] + i - 1;
                int nxt_j = c[1] + j;
                if (0 <= nxt_i && nxt_i < n && 0 <= nxt_j && nxt_j < n)
                {
                    if (count_map[nxt_i][nxt_j] % 2 == 1)
                        count_map[nxt_i][nxt_j] = 0;
                    else if (count_map[nxt_i][nxt_j] % 2 == 0)
                        count_map[nxt_i][nxt_j] = 1;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (count_map[i - 1][j] == 1)
                sub_str += '#';
            else
                sub_str += '.';
        }

        str_map.push_back(sub_str);
    }

    for (int i = 0; i < n; i++)
    {
        cout << str_map[i] << "\n";
    }
    return 0;
}