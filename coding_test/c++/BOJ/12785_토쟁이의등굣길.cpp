#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long total_map[201][201] = {0};
    int w;
    int h;
    cin >> w >> h;
    int school[2] = {w, h};
    int x;
    int y;
    cin >> x >> y;
    int toast[2] = {x - 1, y - 1};

    for (int i = 0; i < w; i++)
        total_map[0][i] = 1;
    for (int i = 0; i < h; i++)
        total_map[i][0] = 1;

    for (int i = 0; i < toast[1] + 1; i++)
    {
        for (int j = 0; j < toast[0] + 1; j++)
        {
            if (total_map[i][j] != 0)
                continue;
            total_map[i][j] = (total_map[i - 1][j] + total_map[i][j - 1]) % 1000007;
        }
    }

    for (int i = toast[0]; i < w; i++)
        total_map[toast[1]][i] = total_map[toast[1]][toast[0]];
    for (int i = toast[1]; i < h; i++)
        total_map[i][toast[0]] = total_map[toast[1]][toast[0]];

    for (int i = toast[1] + 1; i < h; i++)
    {
        for (int j = toast[0] + 1; j < w; j++)
        {
            if (total_map[i][j] != 0)
                continue;
            total_map[i][j] = (total_map[i - 1][j] + total_map[i][j - 1]) % 1000007;
        }
    }

    cout << total_map[h - 1][w - 1];
    return 0;
}
