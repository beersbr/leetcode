#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		if(num.size() == 0)
			return 0;

		sort(num.begin(), num.end());
		int longestRun = 1;
		int currentRun = 1;

		// grab unique values from the array
		num.erase(std::unique(num.begin(), num.end()), num.end());


		for(auto i = num.begin()+1; i != num.end(); ++i)
		{
			if(*(i - 1) + 1 == *i)
			{

				currentRun += 1;
			}
			else
			{
				if(longestRun < currentRun)
					longestRun = currentRun;
				currentRun = 1;
			}
		}

		if(longestRun < currentRun)
			longestRun = currentRun;

		return longestRun;
	}
};

int main(int argc, char *argv[])
{

	std::vector<int> v = {1,2,0,1};

	Solution s;
	cout << s.longestConsecutive(v) << endl;
}