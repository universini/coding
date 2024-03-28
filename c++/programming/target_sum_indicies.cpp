#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> indicesMap; // Map to store indices of elements
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

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indices = twoSum(nums, target);

    if (!indices.empty()) {
        cout << "Indices of the two numbers: " << indices[0] << " and " << indices[1] << endl;
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}
