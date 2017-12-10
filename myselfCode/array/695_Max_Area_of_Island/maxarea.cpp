#include "leetcodeutil.h"

//自己想不出来，别人用的深度搜索

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int row = grid.size();
      int column = grid[0].size();
      int maxAea = 0;
      int temp = 0;
      for (int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j) {
          if (grid[i][j] == 1){
            temp = AreaOfIsland(grid, i, j);
            if (maxAea < temp)
              maxAea = temp;
          }
        }
      }
      return maxAea;
    }

    int AreaOfIsland(vector<vector<int>>& grid, int i, int j){
      if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
        grid[i][j] = 0;     //避免重复计算
        return 1 + AreaOfIsland(grid, i+1, j) + AreaOfIsland(grid, i-1, j) + AreaOfIsland(grid, i, j-1) + AreaOfIsland(grid, i, j+1);
      }
      return 0;
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
