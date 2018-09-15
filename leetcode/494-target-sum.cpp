#include "../leetcodeutil.h"

using namespace std;

/*class Solution {
// 用dp来解, ways[i][j] //数组从0到i和为j的方法数
// ways[i][j] = ways[i-1][j-nums[i]] + ways[i-1][j+num[i]]
// ways[-1][0] = 1; ways[n-1][S] 就是答案
// 暴力求解DFS, O(2^n)
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int n = nums.size();
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum < abs(S)) return 0;
        const int kOffset = sum;
        const int kMaxN = sum * 2 + 1;
        vector<int> ways(kMaxN, 0);
        ways[kOffset] = 1;
        for(int num : nums) {
            vector<int> tmp(kMaxN, 0);
            for(int i = num; i < kMaxN - num; ++i) {
                if(ways[i]) {
                    tmp[i+num] += ways[i];
                    tmp[i-num] += ways[i];
                }
            }
            swap(ways, tmp); //滚动, 进行拷贝
        }

        return ways[S+kOffset];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum < abs(S)) return 0;   //做一个强剪枝
        int res = 0;
        helper(nums, S, 0, res);
        return res;
    }
    // 递归实现, 
    void helper(vector<int>& nums, int S, int start, int& res) {
        if (start >= nums.size()) {
            if (S == 0) ++res; //和为0, 则有一个解
            return;
        }
        helper(nums, S - nums[start], start + 1, res); // 和减去一个数
        helper(nums, S + nums[start], start + 1, res); // 和加上一个数
    }
};
*/
// 可以转换为0-1背包问题来求解
// 有没有子集P的和能不能构成target
// 二维动态规划问题
// dp[i][j] = dp[i-1][j] or dp[i-1][j-ai]
// dp[i-1][j]   ---> dp[i][j+ai] = true;
class Solution {
// 用dp来解, ways[i][j] //数组从0到i和为j的方法数
// ways[i][j] = ways[i-1][j-nums[i]] + ways[i-1][j+num[i]]
// ways[-1][0] = 1; ways[n-1][S] 就是答案
// 暴力求解DFS, O(2^n)
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        S = abs(S);
        const int n = nums.size();
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || (S + sum) % 2 != 0) return 0;
        const int target = (S + sum) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int num : nums) {
            for(int j = target; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }

        return dp[target];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> iv{1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(iv, 3) << endl;

    return 0;
}
