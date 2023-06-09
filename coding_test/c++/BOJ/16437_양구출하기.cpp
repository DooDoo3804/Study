#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct node
{
    char species;
    long long num;
    int root;
};

vector<node> nodes[123457];
int visited[123457] = {0};
stack<node> q;
long long ans;

long long dfs(node a)
{
    long long sub_num = a.num;
    long long sub_num_dfs = 0;

    for (auto b : nodes[a.root])
    {
        if (visited[b.root] == 0)
        {
            visited[b.root] = 1;
            sub_num_dfs += dfs(b);
        }
    }
    if (a.species == 'A')
    {
        return sub_num + sub_num_dfs;
    }
    else if (a.species == 'W')
    {
        if (sub_num_dfs - sub_num > 0)
            return sub_num_dfs - sub_num;
        else
            return 0;
    }
    else if (a.species == 'S')
    {
        return sub_num + sub_num_dfs;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        char species;
        long long num;
        int root;
        cin >> species >> num >> root;
        nodes[root].push_back({species, num, i + 1});
    }

    q.push({'A', 0, 1});

    cout << dfs({'A', 0, 1});
    return 0;
}