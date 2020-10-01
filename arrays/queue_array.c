#include<stdio.h>


int is_empty (int f, int r)
{
    return ((f == -1) && (r == -1));
}

int is_full (int a[], int r)
{
    return ((sizeof(a) - 1) == r);
}

int dequeue (int a[], int *f, int *r)
{
    int n;

    if (is_empty (*f, *r)) {
	    return (-1);
	} else {
	    n = a[*f];
		if (*f == *r) *f = *r = -1;
		else *f++;
	}

	return (n);
}

int cirqueue (int a[], int n, int *f, int *r)
{
    if (((*r+1) % sizeof(a)) == *r) {
		return (-1);
    } else {
	    if (is_empty (*f, *r)) {
	        if (*f == -1) {
			    *f = *r = 0;
			} else {
			    *r = (*r+1) % sizeof(a);
			}
		}

		a[*r] = n;
	}

	return (0);
}

int enqueue (int a[], int n, int *f, int *r)
{
    if (is_full (a, *r)) {
	    return (-1);
    } else {
	    if (is_empty (*f, *r)) {
	        if (*f == -1) {
			    *f = *r = 0;
			} else {
			    *r++;
			}
        }

		a[*r] = n;
    }

	return (0);
}

int main (void)
{
    int a[10];
	int f = -1, r = -1;
	int i;

	for (i=0; i<10; i++) {
	    if (enqueue (a, i, &f, &r) != 0) {
		    printf ("queue is full\n");
		} else {
            printf ("a[i] = %d\n", a[i]);
		}
	}

    return (0);
}
