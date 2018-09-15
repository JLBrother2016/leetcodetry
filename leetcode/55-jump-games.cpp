#include "../leetcodeutil.h"

class Solution {
public:  //2,3,1,1,4
	bool canJump(vector<int> &nums) {
		if(nums.size() == 0)
			return false;
		int reach = 0;
		// i必须访问能够到达的地方去, i <= reach, 超出能访问的访问就返回false
		for(int i = 0; i < nums.size() && i <= reach; ++i) {
			reach = max(nums[i]+i, reach);
			if(reach >= nums.size() - 1) {
				
				return true;
			}
		}
		// cout << reach << endl;

		return false;
	}
};

int main(int argc, char const *argv[])
{
	// vector<int> iv{2,3,1,1,4};
	// vector<int> iv{2,0,0};
	// vector<int> iv{3,2,1,0,4};
	vector<int> iv{0};
	cout << Solution().canJump(iv) << endl;

	return 0;
}

