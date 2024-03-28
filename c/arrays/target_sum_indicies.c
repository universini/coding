#include <stdio.h>

int res[2];

void *twoSum(int *arr, int len, int target) {
  int sum, start = 0, end = len - 1;

  while (start <= end) {
    sum = arr[start] + arr[end];

    if (sum > target)
      end -= 1;
    else if (sum < target)
      start += 1;
    else {
      res[0] = start;
      res[1] = end;
      break;
    }
  }
}

int main(void) {
  int a[] = {2, 7, 11, 15};

  twoSum(a, 4, 18);

  for (int i = 0; i < 2; i++){
    printf("indexes are %d & %d\n", res[0], res[1]);
  }

  return (0);
}
