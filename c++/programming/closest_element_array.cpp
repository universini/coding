#include <iostream>

using namespace std;

int getNearest(int x, int y, int target) {
  if (target - x >= y - target)
    return y;
  else
    return x;
}

int getNearestElement(int arr[], int n, int target) {
  if (target <= arr[0]) return arr[0];
  if (target >= arr[n - 1]) return arr[n - 1];
  int left = 0, right = n, mid = 0;
  while (left < right) {
    mid = (left + right) / 2;
    if (arr[mid] == target) return arr[mid];
    if (target < arr[mid]) {
      if (mid > 0 && target > arr[mid - 1])
        return getNearest(arr[mid - 1], arr[mid], target);
      right = mid;
    } else {
      if (mid < n - 1 && target < arr[mid + 1])
        return getNearest(arr[mid], arr[mid + 1], target);
      left = mid + 1;
    }
  }
  return arr[mid];
}

int main() {
  int arr[] = {2, 5, 6, 7, 8, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 4;
  cout << "Nearest element of " << target
       << " is: " << getNearestElement(arr, n, target);
  cout << endl;
}
