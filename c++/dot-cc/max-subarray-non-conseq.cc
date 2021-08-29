#include <iostream>

using namespace std;

class maxSub {
 public:
  int maxSubArray(int a[], int n) {
    int max1 = a[0];
    int max2 = 0;
    int max_of_max1_max2;
    int i;

    for (i = 1; i < n; i++) {
      max_of_max1_max2 = (max1 > max2) ? max1 : max2;
      // find new max1 and max2
      max1 = max2 + a[i];
      max2 = max_of_max1_max2;
    }

    // return max of max1 and max2
    return ((max1 > max2) ? max1 : max2);
  }
};

int main() {
  int a[] = {5, 5, 10, 100, 10, 5};
  int n = sizeof(a) / sizeof(a[0]);
  maxSub ms;

  cout << "Maximum Subarray Sum : " << ms.maxSubArray(a, n) << endl;
}
