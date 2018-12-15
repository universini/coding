#include<stdio.h>
#include<string.h>

int main (void)
{
    const char *s = "sidde gowda nidagatta";
    const char *t = "nida";
    int ls, lt;
    int i, j;

    ls = strlen(s);
    lt = strlen(t);

    //for (i=0; i<(ls-lt); i++) { /* both works */
    for (i=0; i<ls; i++) {
        j = 0;
        while ((j<lt) && s[i+j] == t[j++]);

        if (j == lt) {
            printf("index: %d\n", i);
        }
    }

    return(0);
}

