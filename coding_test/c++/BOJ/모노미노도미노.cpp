#include <iostream>
#include <algorithm>
#include <vector>

int score;
int blocks;
// 4, 5 가 바운더리
int total_map[10][10] = {0};
int block[3][2][2] = {{{0, 0}, {0, 0}}, {{0, -1}, {0, 0}}, {{-1, 0}, {0, 0}}};
using namespace std;

void move_green(int t, int x, int y)
{
    for (int i = 9; i >= 4; i--)
    {
        int f_check_x = x + block[t][0][0];
        int f_check_y = i + block[t][0][1];
        int s_check_x = x + block[t][1][0];
        int s_check_y = i + block[t][1][1];
        if (total_map[f_check_y][f_check_x] == 0 && total_map[s_check_y][s_check_x] == 0)
        {
            total_map[f_check_y][f_check_x] = 1;
            total_map[s_check_y][s_check_x] = 1;
            break;
        }
    }
}

void move_blue(int t, int x, int y)
{
    for (int i = 9; i >= 4; i--)
    {
        int f_check_x = i + block[t][0][0];
        int f_check_y = y + block[t][0][1];
        int s_check_x = i + block[t][1][0];
        int s_check_y = y + block[t][1][1];
        if (total_map[f_check_y][f_check_x] == 0 && total_map[s_check_y][s_check_x] == 0)
        {
            total_map[f_check_y][f_check_x] = 1;
            total_map[s_check_y][s_check_x] = 1;
            break;
        }
    }
}

void boundary_green()
{
    int over_line = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i + 4 == 4)
            {
                if (total_map[i + 4][j] == 1)
                {
                    over_line = 2;
                    break;
                }
            }
            if (i + 4 == 5)
            {
                if (total_map[i + 4][j] == 1)
                {
                    over_line = 1;
                    break;
                }
            }
        }
        if (over_line != 0)
            break;
    }
    if (over_line == 0)
        return;
    else
    {
        for (int i = 9; i >= 4; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                total_map[i][j] = total_map[i - over_line][j];
                if (i <= 5)
                {
                    total_map[i][j] = 0;
                }
            }
        }
    }
}

void boundary_blue()
{
    int over_line = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i + 4 == 4)
            {
                if (total_map[j][i + 4] == 1)
                {
                    over_line = 2;
                    break;
                }
            }
            if (i + 4 == 5)
            {
                if (total_map[j][i + 4] == 1)
                {
                    over_line = 1;
                    break;
                }
            }
        }
        if (over_line != 0)
            break;
    }
    if (over_line == 0)
        return;
    else
    {
        for (int i = 9; i >= 4; i--)
        {
            for (int j = 0; j < 4; j++)
            {
                total_map[j][i] = total_map[j][i - over_line];
                if (i <= 5)
                {
                    total_map[j][i] = 0;
                }
            }
        }
    }
}

void remove_green(int l)
{
    for (int i = l; i >= 4; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            total_map[j][i] = total_map[j][i - 1];
        }
    }
}

void check_green()
{
    int line = 9;
    while (line >= 4)
    {
        bool made = true;
        for (int j = 0; j < 4; j++)
        {
            if (total_map[line][j] == 0)
            {
                made = false;
                break;
            }
        }
        if (made)
        {
            remove_green(line);
            score++;
        }
        else
            line--;
    }
}

void remove_blue(int l)
{
    for (int i = l; i >= 4; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            total_map[j][i] = total_map[j][i - 1];
        }
    }
}

void check_blue()
{
    int line = 9;
    while (line >= 4)
    {
        bool made = true;
        for (int j = 0; j < 4; j++)
        {
            if (total_map[j][line] == 0)
            {
                made = false;
                break;
            }
        }
        if (made)
        {
            remove_blue(line);
            score++;
        }
        else
            line--;
    }
}

void count_block()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 6; j < 10; j++)
        {
            if (total_map[i][j] == 1)
                blocks++;
            if (total_map[j][i] == 1)
                blocks++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // 초록에서 0,1 행 에 블록이 있으면 블록이 있는 수만큼 아래 행으로 이동
    // 파랑에서 0,1 열 에 블록이 있으면 블록이 있는 수만큼 오른쪽 열로 이동
    // 점수 먼저 얻고 이후에 연한 칸의 블록 이동을 진행(위의 이동)
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t;
        int x;
        int y;
        cin >> t >> x >> y;
        // move
        move_green(t - 1, x, y);
        move_blue(t - 1, x, y);

        check_green();
        check_blue();

        boundary_green();
        boundary_green();
    }
    count_block();
    cout << score << "\n"
         << blocks;
    return 0;
}
