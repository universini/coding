#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the K'th smallest element in the
// array using max-heap
int findKthSmallest(vector<int> const &v, int k)
{
	// create a max-heap using std::priority_queue and
	// insert first k elements of the array into the heap
	// priority_queue<int, vector<int> > pq(v.begin(), v.begin() + k); or
	priority_queue<int> pq(v.begin(), v.begin() + k);

	// do for remaining array elements
	for (int i = k; i < v.size(); i++)
	{
		// if current element is less than the root of the heap
		if (v[i] < pq.top())
		{
			// replace root with the current element
			pq.pop();
			pq.push(v[i]);
		}
	}

	// return the root of max-heap
	return pq.top();
}

// Find K'th smallest element in an array
int main()
{
	vector<int> vec;
	
	vec.push_back(7);
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(9);
	vec.push_back(1);
	
	const size_t k = 3;

	cout << "K'th smallest element in the array is " <<
			findKthSmallest(vec, k);

	return 0;
}
