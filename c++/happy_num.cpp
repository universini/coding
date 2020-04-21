#include<iostream>

using namespace std;

int square_num (int n)
{
	int sum = 0;

	while (n)
	{
		sum = sum + (n%10 * n%10);
		n = n/10;
	}

	return(sum);
}

bool is_happy_num (int n)
{
	int first, second;

	first =  second = n;

	while (first != second)
	{
		first = square_num(first);
		second = square_num(square_num(second));
	}

	return(first == 1);
}

int main (void)
{
	int n;

	cout << "Enter number: ";
	cin >> n;

	cout << "Number is " << is_happy_num(n);
	cout << "\n";

	return(0);
}
