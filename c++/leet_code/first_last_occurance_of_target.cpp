#include <iostream>
#include <vector>

std::vector<int> searchRange(const std::vector<int>& nums, int target) {
    std::vector<int> result(2, -1);

    // Search for the first occurrence of target
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result[0] = mid;
            right = mid - 1;  // Search for the first occurrence to the left
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Search for the last occurrence of target
    left = 0;
    right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result[1] = mid;
            left = mid + 1;  // Search for the last occurrence to the right
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    std::vector<int> result = searchRange(nums, target);

    std::cout << "First occurrence of " << target << " is at index " << result[0] << std::endl;
    std::cout << "Last occurrence of " << target << " is at index " << result[1] << std::endl;

    return 0;
}
