#include "../leetcodeutil.h"

class Solution {
// 一次走1步或者2步, f[n]表示走到第n个台阶的方式数
// f[n] = f[n-1] + f[n-2]
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        int f_n = 2, f_n_1 = 1;
        int ans = 0;
        for(int i = 3; i <= n; ++i){
        	ans = f_n + f_n_1;
        	f_n_1 = f_n;
        	f_n = ans;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
	cout << Solution().climbStairs(3) << endl;

	return 0;
}
