#include "../leetcodeutil.h"

class Solution {
// f[i] = 
public:
    int maxProfit(vector<int>& prices) {
       int maxCur = 0, maxSoFar = 0;
       // *maxCur = current maximum value
	   // *maxSoFar = maximum value found so far 
	   for(int i = 1; i < prices.size(); ++i) {
	   		maxCur = max(0, maxCur += prices[i] - prices[i-1]);
	   		maxSoFar = max(maxCur, maxSoFar);
	   }

	   return maxSoFar;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> iv{7,1,5,3,6,4};
	cout << Solution().maxProfit(iv) << endl;

	return 0;
}

