#include <iostream>
#include <string>

using namespace std;

int total_map[6][6] = {0};

int cert[11][5][2] = {
    {{1, 0}, {2, 0}, {1, 1}, {1, 2}, {1, 3}},
    {{1, 0}, {2, -1}, {1, -1}, {1, 1}, {1, 2}},
    {{1, 0}, {2, -2}, {1, 1}, {1, -2}, {1, -1}},
    {{1, 0}, {2, -3}, {1, -1}, {1, -2}, {1, -3}},
    {{1, 0}, {2, 0}, {1, -1}, {1, 1}, {1, 2}},
    {{1, 0}, {2, -1}, {1, 1}, {1, -2}, {1, -1}},
    {{1, 0}, {1, -1}, {1, -2}, {0, 1}, {0, 2}},
    {{1, 0}, {0, 1}, {1, -1}, {2, -1}, {2, -2}},
    {{1, 0}, {0, 1}, {1, -1}, {1, -2}, {2, -2}},
    {{1, 1}, {0, 1}, {1, 2}, {2, 1}, {1, 3}},
    {{1, 0}, {1, -1}, {1, 1}, {2, 1}, {2, 2}},
};

string check_dice(int x, int y)
{
    bool checks = true;
    for (int c = 0; c < 11; c++)
    {
        for (int cc = 0; cc < 5; cc++)
        {
            checks = true;
            int next_x = x + cert[c][cc][0];
            int next_y = y + cert[c][cc][1];
            if (next_x >= 6 || next_x < 0 || next_y >= 6 || next_y < 0)
            {
                checks = false;
                break;
            }
            else
            {
                if (total_map[next_x][next_y] == 0)
                {
                    checks = false;
                    break;
                }
            }
        }
        if (checks == true)
            return "yes";
    }
    return "no";
}

void rotate()
{
    int sub_map[6][6] = {0};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            sub_map[j][5 - i] = total_map[i][j];
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            total_map[i][j] = sub_map[i][j];
        }
    }
}

void flip()
{
    int sub_map[6][6] = {0};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            sub_map[i][5 - j] = total_map[i][j];
        }
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            total_map[i][j] = sub_map[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 3; i++)
    {
        string ans = "no";
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                cin >> total_map[j][k];
            }
        }

        for (int j = 0; j < 2; j++)
        {

            for (int k = 0; k < 4; k++)
            {
                int ai = 0;
                int bi = 0;
                bool find_one = false;

                for (int x = 0; x < 6; x++)
                {
                    for (int y = 0; y < 6; y++)
                    {
                        if (total_map[x][y] == 1)
                        {
                            ai = x;
                            bi = y;
                            find_one = true;
                            break;
                        }
                    }
                    if (find_one)
                        break;
                }

                ans = check_dice(ai, bi);
                if (ans == "yes")
                {
                    cout << ans << "\n";
                    break;
                }
                rotate();
            }
            if (ans == "yes")
                break;
            flip();
        }
        if (ans == "no")
            cout << ans << "\n";
    }

    return 0;
}
