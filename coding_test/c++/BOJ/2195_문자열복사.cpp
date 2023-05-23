#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string input_s;
    string input_p;
    cin >> input_s >> input_p;
    int ans = 0;

    while (!input_p.empty())
    {
        string next_str = "";
        int count = 0;
        for (int i = 0; i < input_s.size(); i++)
        {
            int sub_count = 0;
            if (input_s[i] == input_p[0])
            {
                for (int j = 0; j < input_s.size() - i; j++)
                {
                    if (input_s[i + j] == input_p[j])
                        sub_count++;
                    else
                        break;
                }
                count = max(count, sub_count);
            }
        }
        for (int i = count; i < input_p.size(); i++)
        {
            next_str += input_p[i];
        }
        input_p = next_str;
        ans++;
    }

    cout << ans;
    return 0;
}
