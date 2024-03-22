#include <iostream>
#include <vector>
#include <algorithm>

void pushZerosToEndAndSort(std::vector<int>& nums) {
    int n = nums.size();
    int nonZeroIndex = 0; // Pointer to track the position for non-zero elements
    
    // Iterate through the array
    for (int i = 0; i < n; ++i) {
        // If the current element is non-zero, swap it with the element at nonZeroIndex
        if (nums[i] != 0) {
            std::swap(nums[i], nums[nonZeroIndex]);
            ++nonZeroIndex; // Increment the nonZeroIndex pointer
        }
    }

    // Sort the subarray consisting of non-zero elements
    std::sort(nums.begin(), nums.begin() + nonZeroIndex);
}

int main() {
    std::vector<int> nums = {0, 3, 0, 2, 0, 4, 5, 0, 8};

    std::cout << "Original Array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    pushZerosToEndAndSort(nums);

    std::cout << "Array after pushing zeros to the end and sorting: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
