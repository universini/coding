#include<iostream>
#include<vector>

using namespace std;

vector<int> first_last_target(const vector<int>& nums, int target)
{
    vector<int> result(2, -1);
    int start;
    int end;

    start = 0; end = nums.size()-1;
    while (start <= end)
    {
        if (nums[start] == target)
        {
            result[0] = start;
            break;
        }

        start++;
    }

    start = 0; end = nums.size()-1;
    while (start <= end)
    {
        if (nums[end] == target)
        {
            result[1] = end;
            break;
        }

        end--;
    }

    return result;
}

int main(void)
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> res = first_last_target(nums, target);

    cout << "First position: " << res[0] << endl;
    cout << "Last position: " << res[1] << endl;

    return 0;
}