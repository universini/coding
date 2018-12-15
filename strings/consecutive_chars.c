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

	for (i=0; i<strlen(s); i++) {
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
