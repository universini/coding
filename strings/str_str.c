#include<stdio.h>
#include<string.h>

int strncase_cmp(const char *s1, const char *s2, int n)
{
	while (n--) {
		if (*s1 != *s2) {
			return(*s1 - *s2);
		}

		s1++;
		s2++;
	}

	return(0);
}

const char *str_str(const char *s1, const char *s2)
{
	int l = strlen(s2);

	while (*s1++) {
		if (strncase_cmp(s1, s2, l) == 0) {
			return(s1);
		}
	}

	return(NULL);
}

int main(void)
{
	char s1[] = "sidde";
	char s2[] = "idd";

	printf("Found sub-string at %s\n", str_str(s1, s2));

	return(0);
}
        
