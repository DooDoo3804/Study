#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(char a, char b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string nums;
    int m = 0;
    cin >> nums >> m;

    int nums_count[10] = {0};
    for (int i = 0; i < nums.size(); i++)
        nums_count[nums[i] - int('0')]++;

    int check_index = 0;
    int max_num = 0;
    bool multi = false;
    bool db_nums = false;
    vector<char> nn;
    vector<int> mm;

    while (m > 0 && check_index < nums.size())
    {

        for (int i = 0; i < 10; i++)
        {
            if (nums_count[9 - i])
            {
                if (nums_count[9 - i] > 1)
                {
                    multi = true;
                    db_nums = true;
                }
                else
                    multi = false;
                max_num = 9 - i;
                break;
            }
        }

        if (nums.size() == 2 && nums_count[0])
        {
            cout << -1;
            return 0;
        }
        else if (nums.size() < 2)
        {
            cout << -1;
            return 0;
        }

        if (check_index == nums.size() - 1 && nums[check_index] == max_num + '0')
            break;

        if (nums[check_index] == max_num + '0')
        {
            nums_count[max_num]--;
            check_index++;
            continue;
        }

        vector<int> sub_index;
        for (int j = nums.size() - 1; j > check_index; j--)
        {
            if (nums[j] == max_num + '0')
            {
                sub_index.push_back(j);
            }
        }

        if (sub_index.size() == 1)
        {
            char sub_char;
            sub_char = nums[check_index];
            nums[check_index] = nums[sub_index[0]];
            nums[sub_index[0]] = sub_char;
            nums_count[max_num]--;
            check_index++;
            m--;
        }
        else
        {
            int sub_return = 0;
            vector<string> sub_vec;
            if (m < sub_index.size())
            {
                for (int s = 0; s < m; s++)
                {
                    string sub_nums = nums;
                    char sub_char;
                    sub_char = sub_nums[check_index];
                    sub_nums[check_index] = sub_nums[sub_index[s]];
                    sub_nums[sub_index[s]] = sub_char;
                    sub_vec.push_back(sub_nums);
                }
            }
            else
            {
                for (int s = 0; s < sub_index.size(); s++)
                {
                    string sub_nums = nums;
                    char sub_char;
                    sub_char = sub_nums[check_index];
                    sub_nums[check_index] = sub_nums[sub_index[s]];
                    sub_nums[sub_index[s]] = sub_char;
                    sub_vec.push_back(sub_nums);
                }
            }
            nn.push_back(nums[check_index]);

            sort(sub_vec.begin(), sub_vec.end());
            nums = sub_vec[0];
            mm.push_back(sub_vec[0][]);
            nums_count[max_num]--;
            check_index++;
            m--;
        }
        sort(nn.begin(), nn.end(), comp);
        sort(mm.begin(), mm.end());
        if (mm.size() > 1 && nn.size() > 1)
        {
            for (int j = 0; j < nn.size(); j++)
            {
                nums[mm[j]] = nn[j];
            }
        }
    }

    if (!db_nums && m && m % 2)
    {
        char sub_char;
        sub_char = nums[nums.size() - 2];
        nums[nums.size() - 2] = nums[nums.size() - 1];
        nums[nums.size() - 1] = sub_char;
    }

    cout << nums;

    return 0;
}