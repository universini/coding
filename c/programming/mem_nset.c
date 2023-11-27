#include <stdio.h>
#include <malloc.h>

/*
 * memset - fill memory with a given value
 */
void *mem_nset(void *s, const unsigned char c, size_t bytes)
{
    unsigned char *p = s;

    while (bytes--) {
      *p++ = c;
    }

    return(s);
}

int main(void) {
  char *data;

  data = malloc(20);

  if (!data)
    return -1;

  mem_nset(data, 'a', 10);

  for (int i=0; i<20; i++)
    printf("Data: %c\n", *(data+i));

  return (0);
}
