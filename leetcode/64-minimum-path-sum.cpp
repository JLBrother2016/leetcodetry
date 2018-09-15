#include "../leetcodeutil.h"

using namespace std;

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         if(grid.size() == 0) return 0;
//         int m = grid.size();
//         int n = grid[0].size();
//         s_ = vector<vector<int>>(m, vector<int>(n, 0));

//         return minPathSum(grid, m-1, n-1);
//     }
// private:  //利用递归先求解路径, 在在路径中寻找和最小, 但是会记录下当前路径的和的值
// 	int minPathSum(vector<vector<int>>& grid,
// 				   			    int i, int j) {
// 		if(i == 0 && j == 0) {
// 			return grid[0][0];
// 		} else if(i < 0 || j < 0) {
// 			return INT_MAX;
// 		} 
// 		// 如果计算过了就直接返回
// 		if(s_[i][j] > 0)
// 			return s_[i][j];
// 		int ans = grid[i][j] + min(minPathSum(grid, i-1, j),
// 								   minPathSum(grid, i, j-1));
// 		s_[i][j] = ans;

// 		return ans;
// 	}

// 	vector<vector<int>> s_;
// };

class Solution {
// 利用动态规划求解和最小, dp[i][j]表示第i, j点最小和的值
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;

        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
        	for(int j = 0; j < n; ++j) {
        		if(i == 0 && j == 0) {
        			dp[i][j] = grid[i][j];
        		} else if(i == 0 && j > 0) {
        			dp[i][j] = dp[i][j-1] + grid[i][j];
        		} else if(i > 0 && j == 0) {
        			dp[i][j] = dp[i-1][j] + grid[i][j];
        		} else {
        			dp[i][j] = min(dp[i-1][j], dp[i][j-1])
        					 + grid[i][j];
        		}
        	}
        }

        return dp[m-1][n-1];
    }
};

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         if (m == 0) return 0;
//         int n = grid[0].size();
        
//         s_ = vector<vector<int>>(m, vector<int>(n, 0));
        
//         return minPathSum(grid, n - 1, m - 1);
//     }    
// private:
//     long minPathSum(const vector<vector<int>>& grid, 
//                    int x, int y) {        
//         if (x == 0 && y == 0) return grid[y][x];
//         if (x < 0 || y < 0) return INT_MAX;
//         if (s_[y][x] > 0) return s_[y][x];
        
//         int ans = grid[y][x] + min(minPathSum(grid, x - 1, y),
//                                    minPathSum(grid, x, y - 1));
//         return s_[y][x] = ans;
//     }
    
//     vector<vector<int>> s_;
// };

int main(int argc, char const *argv[])
{
	vector<vector<int>> iv{{1,3,1},{1,5,1},{4,2,1}};
	cout << Solution().minPathSum(iv) << endl;

	return 0;
}
