#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tcase = 1;
    stack<char> group;
    while (true)
    {
        group = stack<char>();
        string input_str;
        cin >> input_str;

        if (input_str[0] == '-')
            return 0;

        for (int i = 0; i < input_str.size(); i++)
        {
            if (input_str[i] == '{')
                group.push(input_str[i]);
            else if (input_str[i] == '}')
            {
                if (!group.empty() && group.top() == '{')
                    group.pop();
                else if (group.empty())
                    group.push(input_str[i]);
                else if (!group.empty() && group.top() == '}')
                    group.push(input_str[i]);
            }
        }
        int count = 0;
        int cc = group.size() / 2;
        int gcount = 0;
        while (!group.empty())
        {
            char c1 = group.top();
            group.pop();
            char c2 = group.top();
            group.pop();
            if (c1 == c2)
                count++;
            else
                count += 2;
        }
        cout << tcase << ". " << count << "\n";
        tcase++;
    }
    return 0;
}