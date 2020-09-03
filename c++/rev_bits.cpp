#include <stdio.h>

int main (void)
{
    unsigned int n = 0xa;
    int          j = 0;

    printf ("before bits are reversed: %u\n", n);

    for (; n > 0; n >>= 1) {
        j |= (n&0x1);

        //if (n>1) {
            j <<= 1;
        //}
    }

	// drop the current bit
	j >>=1;
	
    printf ("after bits are reversed: %u\n", j);

    return (0);
}
