#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct logs
{
    long long money, remain;
};

vector<logs> bill;

long long find(long long a, long long b)
{
    long long x = max(a, b);
    long long y = min(a, b);
    long long temp = x % y;
    while (temp != 0)
    {
        x = y;
        y = temp;
        temp = x % y;
    }
    return y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    bill.push_back({0, 0});

    long long min_charge = 0;
    bool can_zero = true;

    vector<long long> nums;

    for (int i = 1; i < n + 1; i++)
    {
        long long input;
        long long remain;
        cin >> input >> remain;
        bill.push_back({input, remain});
        if (input > 0)
        {
            if (input + bill[i - 1].remain != remain)
            {
                cout << -1;
                return 0;
            }
        }
        else if (input < 0)
        {
            if (bill[i - 1].remain + input > 0)
            {
                if (bill[i - 1].remain + input != remain)
                {
                    cout << -1;
                    return 0;
                }
            }
            else if (bill[i - 1].remain + input < 0)
            {
                if (remain != 0)
                    can_zero = false;
                min_charge = max(min_charge, remain);
                nums.push_back(remain - input - bill[i - 1].remain);
            }
        }
    }

    if (nums.empty())
    {
        cout << 1;
        return 0;
    }

    sort(nums.begin(), nums.end());

    long long ans = nums.front();

    for (int i = 1; i < nums.size(); i++)
    {
        ans = find(ans, nums[i]);
    }

    if (ans == 1 && can_zero)
        cout << 1;
    else if (ans == 1 && can_zero == false)
        cout << -1;
    else if (ans < min_charge)
        cout << -1;
    else
        cout << ans;

    return 0;
}