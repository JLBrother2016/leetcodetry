#include "../leetcodeutil.h"

// 利用动态规划来求解, f[i] = f[i-1] ? f[i-1] + nums[i] : nums[i];
// 如果f[i-1]小于0, 就重新开始加
// class Solution {
// public:  
//     int maxSubArray(vector<int>& nums) {
//         vector<int> f(nums.size(), 0);
//         if(nums.size() == 0)
//         	return 0;
//         f[0] = nums[0];
//         for(int i = 1; i < nums.size(); ++i) {
//         	f[i] = max(f[i-1] + nums[i], nums[i]);
//         }

//         return *max_element(f.begin(), f.end());
//     }
// };

class Solution {
// 利用动态规划来求解, f[i] = f[i-1] ? f[i-1] + nums[i] : nums[i];
// 如果f[i-1]小于0, 就重新开始加
public:  
    int maxSubArray(vector<int>& nums) {
        int ans;
        if(nums.size() == 0)
        	return 0;
        ans = nums[0];
        int fi = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
        	fi = max(fi + nums[i], nums[i]);
        	ans = max(ans, fi);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> iv{-2,1,-3,4,-1,2,1,-5,4};
	cout << Solution().maxSubArray(iv) << endl;

	return 0;
}
