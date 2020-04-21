#include<iostream>
#include<cstdlib>

using namespace std;

int divide(int n1, int n2)
{
	int sign = 1, quo = 0;

	if (!n1 && !n2) return(0);
	if (!n1 || !n2) exit(1);

	if ((n1*n1) < 0) sign = -1;

	n1 = abs(n1);
	n2 = abs(n2);

	while (n1 >= n2)
	{
		n1 = n1-n2;
		quo++;
	}

	return(sign*quo);
}

int main(void)
{
	int n1, n2;

	cout << "Enter n1 & n2\n";
	cin >> n1;
	cin >> n2;

	cout << divide(n1, n2);
	cout << "\n";

	return(0);
}

