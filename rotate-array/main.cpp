#include <iostream>

class Solution {
public:
	// Does it in O(1) extra space which is 3 ints
	void rotate(int nums[], int n, int k)
	{
		if(k == 0 || ((float)n / (float)k) == 0 || k == n)
			return;

		int emptyIndex = 0;	
		int i = 0;
		int a = nums[i];

		for(int j = 0; j < n; ++j)
		{
			i = (i+k) % n;
			XORswap(a, nums[i]);
			if(i == emptyIndex)
			{
				i += 1;
				a = nums[i];
				emptyIndex = i;
			}
		}
	}	

private:
	void XORswap(int &a, int &b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
};

int main(int argc, char *argv[])
{
	int ar[] = {1, 2, 3, 4, 5, 6, 7};
	int size = 7;

	Solution s;
	s.rotate(ar, size, 0);

	for(int i = 0; i < size; ++i)
		std::cout << ar[i] << " ";
	std::cout << std::endl;

	return 0;
}