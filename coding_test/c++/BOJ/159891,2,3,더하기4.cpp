#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int results[100001] = {0};
    results[1] = 1;
    results[2] = 2;
    results[3] = 3;
    int nums[100001] = {0};
    int max_num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (max_num < nums[i])
            max_num = nums[i];
    }
    for (int i = 4; i < max_num + 1; i++)
    {
        results[i] = results[i - 3] + (i / 2) + 1;
    }
    for (int i : nums)
    {
        if (i == 0)
            break;
        cout << results[i] << "\n";
    }
    return 0;
}