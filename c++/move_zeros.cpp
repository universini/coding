#include<iostream>

using namespace std;

void move_zeros(int a[], int len)
{
	int c = 0;

	for (int i = 0; i<len; i++)
		if (a[i] != 0)
			a[c++] = a[i];

	while (c < len)
		a[c++] = 0;
}

int main(void)
{
	int a[] = {5,0,6,7,0,2,3,8,0,9};
	int len = sizeof(a)/sizeof(a[0]);

	for (int i = 0; i<len; i++)
		cout << a[i] << " ";
	cout << "\n";

	move_zeros(a, len);

	for (int i = 0; i<len; i++)
		cout << a[i] << " ";
	cout << "\n";

	return(0);
}

