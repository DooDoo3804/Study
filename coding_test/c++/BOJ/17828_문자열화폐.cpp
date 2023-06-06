#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int x;

    cin >> n >> x;

    string ans = "";

    int rem_num = n;

    while (rem_num * 26 > x)
    {
        if ((rem_num - 1) * 26 < x)
            break;
        ans += "A";
        x--;
        rem_num--;
        if (x < 0)
        {
            cout << "!";
            return 0;
        }
    }

    if (rem_num * 26 < x)
    {
        cout << "!";
        return 0;
    }

    string suffix = "";
    string middle = "";

    int remain = x % 26;
    int count_Z = x / 26;
    while (count_Z--)
    {
        suffix += "Z";
    }

    if (remain != 0)
        middle = char('A' + remain - 1);

    cout << ans + middle + suffix;

    return 0;
}