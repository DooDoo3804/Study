#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m = 0;
    int n = 0;
    int in_num;
    queue<int> q;
    queue<int> qq;
    cin >> m >> n;

    while (n != 0 && m != 0)
    {
        int dp_m[100000] = {0};
        qq = queue<int>();

        for (int i = 0; i < m; i++)
        {
            q = queue<int>();
            for (int j = 0; j < n; j++)
            {
                cin >> in_num;
                if (j == 0)
                    q.push(in_num);
                else if (j == 1)
                    q.push(max(q.front(), in_num));
                else
                {
                    q.push(max(q.front() + in_num, q.back()));
                    q.pop();
                }
            }
            if (i == 0)
                qq.push(q.back());
            else if (i == 1)
                qq.push(max(qq.front(), q.back()));
            else
            {
                qq.push(max(qq.front() + q.back(), qq.back()));
                qq.pop();
            }
        }
        cout << qq.back() << "\n";
        cin >> m >> n;
        if (m == 0 && n == 0)
            return 0;
    }
    return 0;
}