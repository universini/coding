#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // Map to store indices of elements
    unordered_map<int, int> indicesMap;
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        // If complement exists in the map, return the indices
        if (indicesMap.find(complement) != indicesMap.end()) {
            result.push_back(indicesMap[complement]);
            result.push_back(i);
            return result;
        }

        // Otherwise, store the index of the current element
        indicesMap[nums[i]] = i;
    }

    return result;
}

vector<int> return_indicies(vector<int>& arr, int target) {
    int sum, start = 0, end = arr.size() - 1;
    vector<int> result;

    while (start <= end) {
        sum = arr[start] + arr[end];

        if (sum > target)
            end -= 1;
        else if (sum < target)
            start += 1;
        else {
            result.push_back(start);
            result.push_back(end);
            break;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indices = return_indicies(nums, target);

    if (!indices.empty()) {
        cout << "Indices of the two numbers: "
             << indices[0] << " and " << indices[1] << endl;
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}
