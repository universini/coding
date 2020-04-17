#include<stdio.h>

int res[2];

int *twoSum(int *arr, int len, int target)
{
	int sum, start = 0, end = len-1;

	while (start <= end)
	{
		sum =  arr[start]+arr[end];

		if (sum > target) end-=1;
		else if (sum < target) start+=1;
		else {
			res[0] = start;
			res[1] = end;
			break;
		}
	}

	return(res);
}

int main(void)
{
	int a[] = {2, 7, 11, 15};
	int *r;
	
	r = twoSum(a, 4, 9);

	for (int i=0; i<2; i++)
		printf("indexes are %d & %d\n", r[0], r[1]);

	return(0);
}


