#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct node
{
    int from, to, cost;
};

vector<node> nodes[3001];
int visited[3001] = {0};
int ans[3001] = {0};
int check_cycle = 0;
stack<int> s;
queue<node> q;

void dfs(int a, int start)
{
    visited[a] = 1;
    for (auto n_node : nodes[a])
    {
        if (start == n_node.to && s.size() >= 3)
        {
            check_cycle = true;
            return;
        }
        if (visited[n_node.to] == 0)
        {
            s.push(n_node.to);
            dfs(n_node.to, start);
            if (check_cycle)
                return;
            s.pop();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int from;
        int to;
        cin >> from >> to;
        nodes[from].push_back({from, to, 1});
        nodes[to].push_back({to, from, 1});
    }

    for (int i = 1; i < n + 1; i++)
    {
        s = stack<int>();
        fill(visited, visited + 3001, 0);
        s.push(i);
        dfs(i, i);
        if (check_cycle)
            break;
    }

    fill(visited, visited + 3001, 0);
    while (!s.empty())
    {
        auto f_num = s.top();
        s.pop();
        q.push({f_num, 0, 0});
        visited[f_num] = 1;
    }

    while (!q.empty())
    {
        auto f_num = q.front();
        q.pop();
        for (auto n_node : nodes[f_num.from])
        {
            if (visited[n_node.to] == 0)
            {
                visited[n_node.to] = 1;
                q.push({n_node.to, n_node.to, f_num.cost + 1});
                ans[n_node.to] = f_num.cost + 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
