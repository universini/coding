#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Define structure for elements in min heap
struct HeapNode {
    int element;
    int frequency;
};

// Define comparison function for min heap
struct CompareHeapNode {
    bool operator()(const HeapNode& a, const HeapNode& b) {
        return a.frequency > b.frequency; // Min heap based on frequency
    }
};

// Function to find the k most frequent elements in the array
void kMostFrequent(vector<int>& arr, int k) {
    // Create a hash map to store frequency of elements
    unordered_map<int, int> freqMap;
    for (int num : arr) {
        freqMap[num]++;
    }

    // Create a min heap
    priority_queue<HeapNode, vector<HeapNode>, CompareHeapNode> minHeap;

    // Insert elements with highest frequency into min heap
    for (auto& pair : freqMap) {
        minHeap.push({pair.first, pair.second});
        if (minHeap.size() > k) {
            minHeap.pop(); // Remove the least frequent element
        }
    }

    // Print the k most frequent elements
    cout << k << " most frequent elements: ";
    while (!minHeap.empty()) {
        cout << minHeap.top().element << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    int k = 2;

    kMostFrequent(arr, k);

    return 0;
}
