#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node
{
    char from;
    int time;
    vector<char> to;
    int mtime;
};

bool comp(node a, node b)
{
    return a.to.size() < b.to.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<node> nodes;

    int times[26];
    fill(times, times + 26, -1);

    int check_times[26];
    fill(check_times, check_times + 26, -1);

    for (int i = 0; i < 26; i++)
    {
        string input;
        getline(cin, input);
        char from = ' ';
        string time;
        vector<char> to;
        bool space = false;

        for (int j = 0; j < input.size(); j++)
        {
            if (j == 0)
                from = input[j];
            else if (j >= 2)
            {
                if (input[j] == ' ')
                    space = true;
                else
                {
                    if (space)
                        to.push_back(input[j]);
                    else
                        time.push_back(input[j]);
                }
            }
        }
        if (from != ' ')
        {
            nodes.push_back({from, stoi(time), to, 0});
            times[from - 'A'] = 0;
            check_times[from - 'A'] = stoi(time);
        }
    }

    int ans = 0;

    while (find(times, times + 26, 0) != times + 26)
    {
        sort(nodes.begin(), nodes.end(), comp);
        vector<node> next_nodes;
        int spend_time = 0;
        vector<char> selected;

        for (auto node : nodes)
        {
            vector<char> next_to;
            if (node.to.size() == 0)
            {

                times[node.from - 'A'] = -1;
                check_times[node.from - 'A'] = node.time + node.mtime;
                ans = max(ans, node.time + node.mtime);
                selected.push_back(node.from);
            }
            else
            {
                int max_time = 0;
                for (char c : node.to)
                {
                    if (find(selected.begin(), selected.end(), c) == selected.end())
                    {
                        next_to.push_back(c);
                    }
                    else
                        max_time = max(max_time, check_times[c - 'A']);
                }
                node.mtime = max(max_time, node.mtime);
                next_nodes.push_back({node.from, node.time, next_to, node.mtime});
            }
        }
        nodes = next_nodes;
    }
    cout << ans;
    return 0;
}