#include <iostream>
#include <vector>

/*
 * Given an integer array nums sorted in non-decreasing order,
 * remove some duplicates in-place such that each unique element
 * appears at most twice. The relative order of the elements
 * should be kept the same.
 */
int removeDuplicates(std::vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return n;

    int index = 2; // Starting from the third element

    for (int i = 2; i < n; ++i) {
        if (nums[i] != nums[index - 2]) {
            nums[index++] = nums[i];
        }
    }

    return index;
}

void printArray(const std::vector<int>& nums, int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

    std::cout << "Original array:" << std::endl;
    printArray(nums, nums.size());

    int length = removeDuplicates(nums);

    std::cout << "\nArray after removing duplicates:" << std::endl;
    printArray(nums, length);

    return 0;
}
