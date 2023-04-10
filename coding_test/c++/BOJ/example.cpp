#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool condition(vector<int> a, vector<int> b)
{
    return a[0] > b[0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string nums;
    int m = 0;
    cin >> nums >> m;
    int check_index = 0;

    vector<vector<int>> nums_array;

    for (int i = 0; i < nums.size(); i++)
        nums_array.push_back({nums[i] - int('0'), i});
    sort(nums_array.begin(), nums_array.end(), condition);

    return 0;
}