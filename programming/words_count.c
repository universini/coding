#include<stdio.h>
#include<string.h>

int main (void)
{
	char *str = "Sidde Gowda Nidagatta Malavalli Taluk Mandya District";
	int len = strlen(str);
	int nw = 0;

	for (int i=0; i<len; i++) {
		if (*(str+i) == ' ' ||
            *(str+i) == '\t' ||
            *(str+i) == '\n') {
			++nw;
		}
	}

	printf("Num words: %d\n", ++nw);

	return(0);
}

