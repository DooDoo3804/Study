#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string pal;
    cin >> pal;

    for (int i = pal.size(); i > pal.size() - 2; i--)
    {
        bool flag = false;
        int k = 0;
        while (k < i / 2)
        {
            if (pal[k] != pal[i - k - 1])
            {
                flag = true;
                break;
            }
            k++;
        }
        if (flag == true)
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;
    return 0;
}