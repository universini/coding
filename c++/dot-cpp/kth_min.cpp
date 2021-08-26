#include <iostream>

using namespace std;

void merge_sub_arrays(int arr[], int low, int med, int high) {
  int size1 = med - low;
  int size2 = high - med;
  int i, j, k;
  int arr1[size1];
  int arr2[size2];

  for (i = 0; i < size1; i++) arr1[i] = arr[low + i];

  for (j = 0; j < size2; j++) arr2[j] = arr[med + j];

  // reset counters i & j
  i = j = k = low;

  while (i < size1 && j < size2) {
    if (arr1[i] <= arr2[j]) {
      arr[k++] = arr1[i++];
    } else {
      arr[k++] = arr2[j++];
    }
  }

  while (i < size1) {
    arr[k++] = arr1[i++];
  }

  while (j < size2) {
    arr[k++] = arr2[j++];
  }
}

void merge_sort(int a[], int low, int high) {
  if (low < high) {
    int med = (low + high) / 2;  // or (low+high)/2

    merge_sort(a, low, med);
    merge_sort(a, med + 1, high);

    merge_sub_arrays(a, low, med, high);
  }
}

int find_kth_min(int arr[], int low, int high, int kth) {
  merge_sort(arr, low, high - 1);

  for (int i = 0; i < high; i++) cout << arr[i] << " ";
  cout << "\n";

  return (arr[kth - 1]);
}

int main(void) {
  int arr[] = {7, 9, 5, 3, 10, 2};
  int kth = 3;
  int low = 0, high = sizeof(arr) / sizeof(arr[0]);

  cout << "Kth minimum number is " << find_kth_min(arr, low, high, kth) << endl;
  return (0);
}
