#include "../leetcodeutil.h"

class Solution {
	//利用动态规划求解, 第i,j个位置的走法为f[i][j]
	//递推公式f[i][j] = f[i-1][j] + f[i][j-1] //当i, j都不为0的时候
	//i == 0 或者 j == 0的时候 f[i][j] 应该为1
public:  
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) return 0;
        vector<vector<int>> count(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
        	for(int j = 0; j < n; ++j) {
        		if(i > 0 && j > 0) {
        			count[i][j] = count[i-1][j] + count[i][j-1];
        		} else if(i == 0 || j == 0) {
        			count[i][j] = 1;
        		}
        	}
        }

        return count[m-1][n-1];
    }
};

// 

int main(int argc, char const *argv[])
{
	cout << Solution().uniquePaths(7, 3) << endl;

	return 0;
}
