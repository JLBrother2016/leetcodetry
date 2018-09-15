#include "../leetcodeutil.h"

using namespace std;

// class Solution {
// // 应该用DP来求解, 也可以用递归来做
// // 以字符串中的每一个字符都当作回文串的中间位置, 然后向两边扩散, 每当成功匹配两个左右字符, 结果res自增1, 然后再比较下一对;
// // 回文串分为奇偶数的情况   
// // 暴力求解
// public:
//     int countSubstrings(string s) {
//         if(s.empty()) return 0;
//         int n = s.size(), res = 0;
//         for(int i = 0; i < s.length(); ++i) {
//             res += count(s, i, i);  // 处理奇数
//             res += count(s, i, i+1);// 处理偶数
//         }

//         return res;
//     }
// private:
//     int count(string s, int l, int r) {
//         int ans = 0;
//         while(l >= 0 && r < s.length() && s[l] == s[r]) {
//             --l;
//             ++r;
//             ++ans;
//         }
//         return ans;
//     }
// };
class Solution {
// 应该用DP来求解, 也可以用递归来做
// 以字符串中的每一个字符都当作回文串的中间位置, 然后向两边扩散, 每当成功匹配两个左右字符, 结果res自增1, 然后再比较下一对;
// 回文串分为奇偶数的情况   
// 暴力求解
// dp[i][j]定义的是范围[i, j]之间的子字符串的个数, 二维数组记录i到j是否是回文串
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int n = s.size(), res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && ((j - i <= 2) || dp[i+1][j-1]);
                if(dp[i][j]) ++res;
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().countSubstrings("aaa") << endl;

    return 0;
}

