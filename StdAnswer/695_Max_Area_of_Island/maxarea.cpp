#include "leetcodeutil.h"

//自己想不出来，别人用的深度搜索, 也有广度搜索
/* //BFS
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == 1) ans = max(ans, dfs(grid, i, j));
        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size(), area = 1;
        grid[row][col] = 2;
        vector<int> dir({-1,0,1,0,-1});
        for (int i = 0; i < 4; i++) {
            int r = row+dir[i], c = col+dir[i+1];
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) 
                area += dfs(grid, r, c);
        }
        return area;
    }
};
*/  
/*//BFS
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == 1) ans = max(ans, area(grid, i, j));
        return ans;
    }
private:
    int area(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size(), area = 1;
        queue<pair<int,int>> myq;
        myq.push({row, col});
        grid[row][col] = 2;
        vector<int> dir({-1,0,1,0,-1});
        while (!myq.empty()) {
            int z = myq.front().first, x = myq.front().second;
            myq.pop();
            for (int i = 0; i < 4; i++) {
                int r = z+dir[i], c = x+dir[i+1];
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                    grid[r][c] = 2;
                    area++;
                    myq.push({r,c});
                }
            }
        }
        return area;
    }
};   
*/

class Solution {
private:
    vector<pair<int, int>> dirs = { {1, 0} , {-1, 0} , {0, 1} , {0, -1} };
    
    int getSize(vector<vector<int>> &grid, int i, int j) {  
        if (i >= grid.size() || i < 0 ||
            j >= grid[0].size() || j < 0 || (grid[i][j] == 0)) {
            return 0;
        }
          
        grid[i][j] = 0;
        
        return 1 + getSize(grid, i+1, j) 
                 + getSize(grid, i-1, j)
                 + getSize(grid, i, j+1)
                 + getSize(grid, i, j-1);
        
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        if (grid.empty() || grid[0].empty()) return {};
        
        int max_size = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                
                if (grid[i][j] == 1) {
                    int cur_size = getSize(grid, i, j);
                    max_size = max(max_size, cur_size);
                }
                
            }
        }
        
        return max_size;
        
    }
};

int main(int argc, char const *argv[])
{
  vector<vector<int>> vect{{0,0,0,0,0,0,0,0}};
  vector<vector<int>> vect1{ {0,0,1,0,0,0,0,1,0,0,0,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};

  cout << Solution().maxAreaOfIsland(vect1) << endl;                           

  return 0;
}
