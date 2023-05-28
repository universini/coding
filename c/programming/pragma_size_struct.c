#include <stdio.h>

struct A3 {
  char a;
  double b;
  char c;
  int d[0];
};

#pragma pack(push, 1)
struct A4 {
  char a;
  double b;
  char c;
  int d[0];
};
#pragma pack(pop)

int main(void) {
  int a[0];

  printf("size of array: %lu\n", sizeof(a));

  printf("size of double: %lu A3: %lu A4: %lu\n", sizeof(double),
         sizeof(struct A3), sizeof(struct A4));
  return (0);
}
