#include <stdio.h>

void merge_sorted(int a[], int b[], int m, int n, int c[]) {
  int i = 0, j = 0, k = 0;

  while (i < m && j < n) {
    if (a[i] < b[j]) {
      c[k] = a[i];
      i++;
      k++;
    } else if (a[i] > b[j]) {
      c[k] = b[j];
      j++;
      k++;
    } else { /* append same from both arrays e.g 2 */
      c[k++] = a[i];
      c[k] = b[j];
      i++;
      j++;
      k++;
    }
  }

  while (i < m) c[k++] = a[i++];
  while (j < n) c[k++] = b[j++];

  return;
}

int main(void) {
  int a[] = {2, 4, 5, 7, 8, 9};
  int b[] = {1, 2, 3, 6, 8, 9, 11};
  int m = sizeof(a) / sizeof(a[0]);
  int n = sizeof(b) / sizeof(b[0]);
  int c[m + n];

  printf("{");

  merge_sorted(a, b, m, n, c);

  for (int i = 0; i < m + n; i++) {
    printf(" %d ", c[i]);
  }

  printf("}\n");

  return (0);
}
