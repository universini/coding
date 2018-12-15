#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *cons_chars(const char *s)
{
	int count;
	int i, j = 1, k = 0;
	char *t;
	char c[10];

	count = 1;

	t = (char *) malloc(strlen(s)*sizeof(char));

	for (i=0; i<strlen(s)-1; i++) {
		if (*(s+i) == *(s+j)) {
			count++;
		} else {
			sprintf(c,"%d", count);
			*(t+k++) = *(s+i);
			strcpy((t+k++), c);
			count = 1;
		}
		j++;
	}

	/* copy the last char */
	sprintf(c,"%d", count);
	*(t+k++) = *(s+i);
	strcpy((t+k++), c);
	t[k] = '\0';

	return(t);
}

int main(void)
{
	char s[] = "aabbaaccdddhhhherr";
	char *t;

	t = cons_chars(s);
	printf("%s\n", t);

	return(0);
}
