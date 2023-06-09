#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    int from, to, cost;
};

bool comp(node a, node b)
{
    return a.to < b.to;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int d;
    cin >> n >> d;

    vector<node> nodes;

    int dist[10001] = {0};

    for (int i = 0; i < n; i++)
    {
        int from;
        int to;
        int cost;
        cin >> from >> to >> cost;
        nodes.push_back({from, to, cost});
    }

    sort(nodes.begin(), nodes.end(), comp);
    nodes.push_back({0, 0, 0});
    int index = 0;
    for (int i = 1; i < d + 1; i++)
    {
        dist[i] = dist[i - 1] + 1;
        if (i == nodes[index].to)
        {
            do
            {
                dist[nodes[index].to] = min(min(dist[nodes[index].to], dist[nodes[index].to - 1] + 1), dist[nodes[index].from] + nodes[index].cost);
                index++;
            } while (nodes[index].to == i);
        }
    }

    cout << dist[d];
    return 0;
}
