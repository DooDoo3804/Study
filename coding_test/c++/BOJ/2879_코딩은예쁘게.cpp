#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;

    vector<int> selected;

    int now_indent[1001] = {0};
    int indent[1001] = {0};

    for (int i = 0; i < n * 2; i++)
    {
        int input;
        cin >> input;
        if (i < n)
            now_indent[i] = input;
        else
            indent[i - n] = now_indent[i - n] - input;
    }

    int ans = 0;
    while (count(indent, indent + 1001, 0) != 1001)
    {
        selected = vector<int>();
        int min_indent[2] = {0};
        int toggle = 0;
        for (int i = 0; i < n + 1; i++)
        {
            if (selected.empty() && indent[i] == 0)
                continue;
            else if (selected.empty() && indent[i] != 0)
            {
                selected.push_back(i);
                toggle = indent[i];
                min_indent[1] = indent[i];
                min_indent[0] = i;
            }
            else
            {
                if (!selected.empty() && indent[i] == 0 || toggle * indent[i] < 0)
                {
                    for (int j : selected)
                    {
                        indent[j] -= min_indent[1];
                    }
                    if (min_indent[1] < 0)
                        ans -= min_indent[1];
                    else
                        ans += min_indent[1];
                    break;
                }
                else if (toggle * indent[i] > 0)
                {
                    selected.push_back(i);
                    toggle = indent[i];
                    if (toggle > 0)
                        min_indent[1] = min(min_indent[1], indent[i]);
                    if (toggle < 0)
                        min_indent[1] = max(min_indent[1], indent[i]);
                }
            }
        }
    }

    cout << ans;
    return 0;
}