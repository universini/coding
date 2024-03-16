#include <iostream>
#include <vector>

void mergeArrays(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int index1 = m - 1; // Index of last element in nums1
    int index2 = n - 1; // Index of last element in nums2
    int mergedIndex = m + n - 1; // Index where elements will be merged

    // Start from the end of both arrays and compare elements
    while (index1 >= 0 && index2 >= 0) {
        if (nums1[index1] >= nums2[index2]) {
            // If element from nums1 is greater, place it in mergedIndex
            nums1[mergedIndex] = nums1[index1];
            index1--;
        } else {
            // Otherwise, place element from nums2 in mergedIndex
            nums1[mergedIndex] = nums2[index2];
            index2--;
        }
        mergedIndex--;
    }

    // If there are remaining elements in nums2, copy them to nums1
    while (index2 >= 0) {
        nums1[mergedIndex] = nums2[index2];
        index2--;
        mergedIndex--;
    }
}

int main() {
    std::vector<int> nums1 = {1, 3, 5, 0, 0, 0}; // Example nums1 array (with extra space)
    std::vector<int> nums2 = {2, 4, 6}; // Example nums2 array
    int m = 3; // Number of elements in nums1
    int n = 3; // Number of elements in nums2

    mergeArrays(nums1, m, nums2, n);

    std::cout << "Merged Array: ";
    for (int num : nums1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
