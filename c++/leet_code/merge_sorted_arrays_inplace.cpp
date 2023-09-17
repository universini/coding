#include <iostream>
#include <vector>

/*
 * You are given two integer arrays nums1 and nums2, sorted in
 * non-decreasing order, and two integers m and n, representing
 * the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into a single array sorted in non-decreasing
 * order. The final sorted array should not be returned by the function,
 * but instead be stored inside the array nums1. To accommodate this,
 * nums1 has a length of m + n, where the first m elements denote the
 * elements that should be merged, and the last n elements are set to 0
 * and should be ignored. nums2 has a length of n.
 */
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int index1 = m - 1;
    int index2 = n - 1;
    int mergedIndex = m + n - 1;

    while (index1 >= 0 && index2 >= 0) {
        if (nums1[index1] > nums2[index2]) {
            nums1[mergedIndex--] = nums1[index1--];
        } else {
            nums1[mergedIndex--] = nums2[index2--];
        }
    }

    // Copy remaining elements from nums2 if any
    while (index2 >= 0) {
        nums1[mergedIndex--] = nums2[index2--];
    }
}

void printArray(const std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    std::vector<int> nums2 = {2, 5, 6};
    int n = 3;

    std::cout << "Array 1 before merge:" << std::endl;
    printArray(nums1);

    std::cout << "Array 2:" << std::endl;
    printArray(nums2);

    merge(nums1, m, nums2, n);

    std::cout << "\nArray 1 after merge:" << std::endl;
    printArray(nums1);

    return 0;
}
