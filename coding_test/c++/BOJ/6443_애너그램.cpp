#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;

        sort(input.begin(), input.end());

        for (int j = 0; j < input.size(); j++)
        {
            cout << input[j];
        }

        cout << "\n";

        while (next_permutation(input.begin(), input.end()))
        {
            for (int j = 0; j < input.size(); j++)
            {
                cout << input[j];
            }
            cout << "\n";
        }
    }

    return 0;
}