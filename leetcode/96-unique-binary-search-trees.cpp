#include "../leetcodeutil.h"

class Solution {
// 一般返回有或没有, 或者结果的数量, 一般可以利用动态规划来求解
// f[i]表示第i个节点有多少中解
// k个节点, j个左节点, k - j - 1个右节点
public:
    int numTrees(int n) {
    	if(n < 1) return 0;
    	vector<int> nums(n + 1, 0);
    	nums[0] = 1;
    	nums[1] = 1;
    	for(int i = 2; i <= n; ++i) { // i为左子树的节点个数
    		for(int j = 0; j < i; ++j) {
    			nums[i] += (nums[j] * nums[i-j-1]);
    		}
    	}

    	return nums[n];
    }
};

class Solution {
// 一看就是DP问题, 当前的问题与前面的子问题相关
// f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-2)*f(1) + f(n-1)*f(0)
public:
    int numTrees(int n) {
        vector<int> f;
        f.push_back(1);
        for (int i = 1; i <= n; ++i) {
            int t = 0;
            for (int j = 0; j < i; ++j)
                t += f[j] * f[i-j-1];  //f[j]左孩子有多少个, f[i-j-1]右孩子有多少个
            f.push_back(t);
        }
        return f.back();
    }
};

int main(int argc, char const *argv[])
{
	cout << Solution().numTrees(3) << endl;

	return 0;
}

