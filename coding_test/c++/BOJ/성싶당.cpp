#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int g;
    int k;
    cin >> n >> g >> k;
    vector<vector<int>> ingredients;
    for (int i = 0; i < n; i++)
    {
        int s;
        int l;
        int o;
        cin >> s >> l >> o;
        ingredients.push_back({s, l, o});
    }

    sort(ingredients.begin(), ingredients.end(), compare);

    return 0;
}