#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e18

struct node
{
    long long from, to, cost;
};

vector<node> buildings[100001];

bool operator<(node a, node b)
{
    return a.cost > b.cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    long long m;
    long long k;

    cin >> n >> m >> k;
    ;
    for (int i = 0; i < m; i++)
    {
        long long u;
        long long v;
        long long c;
        cin >> u >> v >> c;
        buildings[v].push_back({v, u, c});
    }

    vector<long long> meeting_room;

    long long ans[100001];
    fill(ans, ans + 100001, INF);

    priority_queue<node> pq;

    for (int i = 0; i < k; i++)
    {
        long long input;
        cin >> input;
        ans[input] = 0;
        pq.push({input, 0, 0});
    }

    long long result[2] = {0};

    while (!pq.empty())
    {
        auto now = pq.top();
        pq.pop();

        if (ans[now.from] < now.cost)
            continue;

        if (ans[now.from] != INF && ans[now.from] > result[0])
        {
            result[0] = ans[now.from];
            result[1] = now.from;
        }

        for (auto next_node : buildings[now.from])
        {
            long long n_cost = now.cost + next_node.cost;
            if (ans[next_node.to] == 0)
                continue;
            if (n_cost < ans[next_node.to])
            {
                ans[next_node.to] = n_cost;
                pq.push({next_node.to, 0, n_cost});
            }
        }
    }
    cout << result[1] << "\n"
         << result[0];
    return 0;
}
