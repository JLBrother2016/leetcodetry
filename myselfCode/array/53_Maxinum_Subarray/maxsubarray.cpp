#include "../leetcodeutil.h"
// 动态规划问题
// maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i]; 
/*class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int maxsub = nums[0];
        vector<int> dp(len);
        dp[0] = maxsub;
        for(int i = 1; i < len; ++i){
          dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i - 1] : 0);
          maxsub = max(maxsub, dp[i]);
        }
        return maxsub;
    }
};*/
class Solution {
public:
    int maxSubArray(vector<int> A) {
        int n = A.size();
        int ans = A[0], i, sum = 0;
        for(i = 0; i < n; i++){
            sum += A[i];
            ans = max(sum, ans);
            sum = max(sum, 0);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{-2,1,-3,4,-1,2,1,-5,4};
  vector<int> vect1{1, 2, 3};
  vector<int> vect2{2,4,1};

  cout << Solution().maxSubArray(vect) << endl;

  return 0;
}