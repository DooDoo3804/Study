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

    for (int i = 0; i < 26; i++)
    {
        string input;
        getline(cin, input);
        char from = ' ';
        int time = 0;
        vector<char> to;

        for (int j = 0; j < input.size(); j++)
        {
            if (j == 0)
                from = input[j];
            else if (j == 2)
                time = (int)input[2] - '0';
            else if (j >= 4)
            {
                to.push_back(input[j]);
            }
        }
        if (from != ' ')
        {
            nodes.push_back({from, time, to});
            times[i] = 0;
        }
    }

    sort(nodes.begin(), nodes.end(), comp);

    int ans = 0;

    while (find(times, times + 26, 0) != times + 26)
    {
        vector<node> next_nodes;
        node pre_node = nodes.front();
    }
    return 0;
}