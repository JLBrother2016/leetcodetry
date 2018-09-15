#include "../leetcodeutil.h"

using namespace std;

// class Solution {
// // prefix sum这个技巧用来加速的, 预先计算第0个元素到第i个元素的值
// // 找前缀
// // 连续的子数组和是连续的
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         // 利用前缀和来暴力求解
//         const int n = nums.size();
//         vector<int> sums(n+1, 0);
//         for(int i = 1; i <= n; ++i) {
//             sums[i] = sums[i-1] + nums[i-1];
//         }
//         int ans = 0;
//         for(int i = 0; i < n; ++i) {
//             for(int j = i; j < n; ++j) {
//                 if(sums[j+1] - sums[i] == k) 
//                     ++ans;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
// prefix sum这个技巧用来加速的, 预先计算第0个元素到第i个元素的值
// 找前缀
// 连续的子数组和是连续的
public:
    int subarraySum(vector<int>& nums, int k) {
        // 利用hash table来做
        // 用一个哈希表来建立连续子数组之和跟其出现次数之间的映射
        // 因为我们的解题思路是遍历数组中的数字
        // 建立hash表的目的是为了让我们可快速的查找sum-k是否存在, 即是否有连续组数组的和为sum-k
        if(nums.empty()) return 0;
        unordered_map<int, int> counts{{0, 1}};
        int sum = 0;
        int ans = 0;
        for(const int num : nums) {
            sum += num;
            ans += counts[sum - k];
            ++counts[sum];
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> iv{1, 1, 1};
    cout << Solution().subarraySum(iv, 2) << endl;

    return 0;
}

