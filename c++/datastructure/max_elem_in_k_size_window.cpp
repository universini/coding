#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> maxInWindow_1(const vector<int>& arr, int k) {
    vector<int> result;
    deque<int> dq;

    // Process the first window separately
    for (int i = 0; i < k; ++i) {
        // Remove elements smaller than the current element from the back
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // Process the remaining windows
    for (int i = k; i < arr.size(); ++i) {
        // The front of the deque contains the maximum element in the current window
        result.push_back(arr[dq.front()]);

        // Remove elements outside the current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove elements smaller than the current element from the back
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        // Add the current index to the deque
        dq.push_back(i);
    }

    // Add the maximum element of the last window
    result.push_back(arr[dq.front()]);

    return result;
}

// Method to find the maximum for each
// and every contiguous subarray of size K.
vector<int> maxInWindow_2(vector<int>& arr, int k)
{
    vector<int> result;
    int n = arr.size();
    int j, max;
 
    for (int i = 0; i <= n - k; i++) {
        max = arr[i];
 
        for (j = 1; j < k; j++) {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        result.push_back(max);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxInWindow_2(arr, k);

    cout << "Maximum elements in each window of size " << k << " are:" << endl;
    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}
