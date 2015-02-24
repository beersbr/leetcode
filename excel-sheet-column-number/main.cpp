#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
    	int base = 26;
    	int charOffset = 'A'-1;
    	int total = 0;

    	for(int i = s.size()-1; i >= 0; --i)
    	{
    		int power = (s.size()-1) - i;
    		int number = ((char)s[i] - charOffset);
    		total += (number * pow(base, power));
    	}

    	return total;
    }
};

int main(int argc, char *argv[])
{
	Solution t;
	int s = t.titleToNumber("AA");
	std::cout << s << std::endl;
	return 0;
}